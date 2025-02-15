/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include "StringFormat.h"

namespace StringUtils {
    constexpr size_t THREAD_LOCAL_BUFFER_SIZE = 1024;
    thread_local std::vector<char> formatBuffer(THREAD_LOCAL_BUFFER_SIZE);
}