/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#ifndef UNITTESTBOT_TESTSWRITER_H
#define UNITTESTBOT_TESTSWRITER_H


#include "Tests.h"
#include "streams/BaseWriter.h"
#include "streams/IStreamWriter.h"
#include "streams/ServerWriter.h"
#include "stubs/Stubs.h"
#include "utils/ExecUtils.h"

#include <protobuf/testgen.grpc.pb.h>

class TestsWriter : public utbot::ServerWriter<testsgen::TestsResponse> {
public:
    explicit TestsWriter(grpc::ServerWriter<testsgen::TestsResponse> *writer);

    virtual void writeTestsWithProgress(tests::TestsMap &testMap,
                                        std::string const &message,
                                        const fs::path &testDirPath,
                                        std::function<void(tests::Tests &)> &&functor) = 0;

    virtual void writeStubs(const std::vector<Stubs> &synchronizedStubs) {
        // Default implementation is empty.
    }

protected:
    void writeCompleted(tests::TestsMap const &testMap, int totalTestsCounter);

private:
};


#endif // UNITTESTBOT_TESTSWRITER_H
