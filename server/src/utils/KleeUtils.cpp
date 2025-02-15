/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include "KleeUtils.h"

#include "LogUtils.h"
#include "Paths.h"
#include "TimeExecStatistics.h"

#include "loguru.h"

#include <run_klee/run_klee.h>

#include <fcntl.h>
#include <fstream>
#include <future>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>

namespace KleeUtils {
    using namespace std::chrono;
    using std::string;

    //Operators exclude brackets
    const std::unordered_set<std::string_view> CPP_OPERATORS = {
            "+", "-", "*", "/", "%", "^", "&", "|", "~", "!",
            "=", "<", ">", "+=", "-=", "*=", "/=", "%=", "^=",
            "&=", "|=", "<<", ">>", ">>=", "<<=", "==", "!=",
            "<=", ">=", "<=>", "&&", "||", "++", "--", ",",
            "->*", "->"
    };



    bool isBrackets(std::string_view operatorName, const char& open_bracket) {
        //Brackets operators map
        const std::unordered_map<char, char> CPP_BRACKET_OPERATORS = {
                {'(', ')'},
                {'[', ']'}
        };

        if(!operatorName.empty() && operatorName[0] == open_bracket &&
                operatorName[operatorName.size() - 1] == CPP_BRACKET_OPERATORS.at(open_bracket)) {
            return std::all_of(operatorName.begin() + 1, operatorName.end() - 1,
                            [](char c) {
                                return std::isspace(static_cast<unsigned char>(c));
                            });
      }
      return false;
    }

    string getRenamedOperator(std::string_view methodName) {
        const std::unordered_map<char, std::string> SYMBOL_TO_NAME = {
                {'+', "plus"}, {'-', "minus"}, {'*', "asterisk"},
                {'/', "slash"}, {'%', "percent"}, {'^', "caret"},
                {'&', "ampersand"}, {'|', "vertical"}, {'~', "tilde"},
                {'!', "exclamation"}, {'=', "equal"}, {'<', "less"},
                {'>', "great"}, {',', "comma"}
        };

        const std::string OPERATOR = "operator";

        if (methodName.size() > OPERATOR.size() && methodName.substr(0, OPERATOR.size()) == OPERATOR) {
            std::stringstream newName;
            newName << "operator";
            std::string_view operatorEnd = methodName.substr(8, methodName.size());
            auto operator_name = CPP_OPERATORS.find(operatorEnd);
            if (isBrackets(operatorEnd, '(')) {
                newName << "_parentheses";
            } else if (isBrackets(operatorEnd, '[')) {
                newName << "_brackets";
            } else if (operator_name != CPP_OPERATORS.end()) {
                for(const char &ch : operatorEnd) {
                    newName << "_" << SYMBOL_TO_NAME.at(ch);
                }
            } else {
                return {methodName.begin(), methodName.end()};
            }
            return newName.str();
        }
        return {methodName.begin(), methodName.end()};
    }

    string entryPointFunction(const tests::Tests &tests,
                              const std::string &methodName,
                              bool needToMangle) {
        string methodNewName = getRenamedOperator(methodName);
        string mangledPath = Paths::mangle(tests.relativeFileDir / tests.sourceFileNameNoExt);
        mangledPath = StringUtils::stringFormat("klee_entry__%s_%s", mangledPath, methodNewName);
        if (needToMangle && Paths::isCXXFile(tests.sourceFilePath)) {
            mangledPath = "_Z" + std::to_string(mangledPath.size()) + mangledPath + "iPPcS0_";
        }
        return mangledPath;
    }

    string postSymbolicVariable(const string &variableName) {
        return variableName + "_post";
    }
}