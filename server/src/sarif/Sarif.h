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
            const std::string sarifName = "saifOutput.sarif";
            const std::string defaultVersion = "2.1.0";
            const std::string defaultToolName = "utbotSARIF";
            const std::string defaultScheme = "https://schemastore.azurewebsites.net/schemas/json/sarif-2.1.0-rtm.4.json";
            json sarifJson;
        public:
            Sarif();
            std::size_t loadRuns(const fs::path &jsonPath);
            void writeSarifFile(const fs::path &runsPath);
    };
}

#endif // SARIF_H_