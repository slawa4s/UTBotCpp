/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#ifndef UNITTESTBOT_FileTESTGEN_H
#define UNITTESTBOT_FileTESTGEN_H

#include "ProjectTestGen.h"


class FileTestGen : public ProjectTestGen {
public:
    fs::path filepath;

    FileTestGen(const testsgen::FileRequest &request,
                ProgressWriter *progressWriter,
                bool testMode);

    ~FileTestGen() override = default;

    string toString() override;

    void setModuleTestingSources(const vector<fs::path> &moduleFiles);
};


#endif // UNITTESTBOT_FileTESTGEN_H
