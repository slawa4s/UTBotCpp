/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#ifndef UNITTESTBOT_STUBSPRINTER_H
#define UNITTESTBOT_STUBSPRINTER_H

#include "Printer.h"
#include "ProjectContext.h"
#include "stubs/Stubs.h"
#include "types/Types.h"

namespace printer {
    class StubsPrinter : Printer {
    public:
        StubsPrinter(utbot::Language srcLanguage);

        Stubs genStubFile(const Tests &tests,
                          const types::TypesHandler &typesHandler,
                          const utbot::ProjectContext &projectContext);
    };
}


#endif // UNITTESTBOT_STUBSPRINTER_H
