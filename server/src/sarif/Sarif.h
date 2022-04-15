#ifndef SARIF_H_
#define SARIF_H_

#include <string>
#include "utils/JsonUtils.h"
#include "utils/path/FileSystemPath.h"
#include "loguru.h"

using json = nlohmann::json;

namespace sarif {
    struct Sarif {
        private:
            const std::string default_version = "2.1.0";
            const std::string default_tool_name = "utbotSARIF";
            const std::string default_sheme = "https://schemastore.azurewebsites.net/schemas/json/sarif-2.1.0-rtm.4.json";
            json sarif_json;
        public:
            Sarif();
            void writeSarifFile(const fs::path &jsonPath);
    };
}

#endif // SARIF_H_