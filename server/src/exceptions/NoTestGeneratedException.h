/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#ifndef UNITTESTBOT_NOTESTGENERATEDEXCEPTION_H
#define UNITTESTBOT_NOTESTGENERATEDEXCEPTION_H

#include "BaseException.h"

struct NoTestGeneratedException : public BaseException {
    explicit NoTestGeneratedException() : BaseException("") {}

    explicit NoTestGeneratedException(const string& message) : BaseException("") {
        this->message = defaultMessage + " " + message;
    }

    [[nodiscard]] const char *what() const noexcept override {
        if (message.empty()) {
            return defaultMessage.c_str();
        }
        return message.c_str();
    }

private:
    string defaultMessage = "No tests generated.";
};

#endif //UNITTESTBOT_NOTESTGENERATEDEXCEPTION_H
