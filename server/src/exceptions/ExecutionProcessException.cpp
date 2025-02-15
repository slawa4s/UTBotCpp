/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include "ExecutionProcessException.h"

ExecutionProcessException::ExecutionProcessException(string cmd, fs::path logFilePath) : cmd(std::move(cmd)), logFilePath(std::move(logFilePath)) {}

const char *ExecutionProcessException::what() const noexcept {
    return cmd.c_str();
}

string ExecutionProcessException::getLogFilePath() const noexcept {
    return logFilePath;
}
