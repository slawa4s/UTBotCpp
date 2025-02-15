/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#ifndef UNITTESTBOT_KLEECONSTRAINTSPRINTER_H
#define UNITTESTBOT_KLEECONSTRAINTSPRINTER_H

#include "Printer.h"
using std::string;
using std::vector;
using std::unordered_map;

using tests::Tests;

namespace printer {
    class KleeConstraintsPrinter: public Printer {
    public:
        explicit KleeConstraintsPrinter(const types::TypesHandler *typesHandler, utbot::Language srcLanguage);

        utbot::Language getLanguage() const override;

        Stream genConstraints(const string &name, const types::Type& type);

        Stream genConstraints(const Tests::MethodParam &param);

        void setTabsDepth(const size_t depth) {
            tabsDepth = depth;
        }

    private:
        types::TypesHandler const *typesHandler;

        struct ConstraintsState {
            std::string paramName;
            std::string curElement;
            types::Type curType;
            bool endString;
            int depth = 0;
        };

        void genConstraintsForPrimitive(const ConstraintsState &state);

        void genConstraintsForPointerOrArray(const ConstraintsState &state);

        void genConstraintsForMultiPointerOrArray(const ConstraintsState &state,
                                                  vector<size_t> sizes);

        void genConstraintsForStruct(const ConstraintsState &state);

        void genConstraintsForEnum(const ConstraintsState &state);

        void genConstraintsForUnion(const ConstraintsState &state);

        void genConstraintsForPointerInStruct(const ConstraintsState &state);

        void genConstraintsForPointerInUnion(const ConstraintsState &state);

        static std::string cexConstraints(const string &name, const types::Type &type);
    };
}



#endif // UNITTESTBOT_KLEECONSTRAINTSPRINTER_H
