#include "Sarif.h"
#include "gtest/gtest.h"
#include "utils/JsonUtils.h"
#include "Paths.h"
#include "loguru.h"

namespace sarif {
    Sarif::Sarif() {
        LOG_S(DEBUG) << "Make sarif";
        sarif_json["version"] = default_version;
        sarif_json["$schema"] = default_sheme;
        sarif_json["runs"]["tool"]["driver"]["name"] = default_tool_name;
        sarif_json["runs"]["results"] = json::array();
    }

    void Sarif::writeSarifFile(const fs::path &jsonPath) {
        LOG_S(DEBUG) << "Load Sarif to " << jsonPath.c_str();
        JsonUtils::writeJsonToFile(jsonPath, sarif_json);
    }

    std::size_t Sarif::loadRuns(const fs::path &runsFolder) {
        if (!fs::exists(runsFolder)) {
            LOG_S(WARNING) << runsFolder.string() << " path not valid";
            return -1;
        }
        CollectionUtils::FileSet allFiles = Paths::findFilesInFolder(runsFolder);
        std::size_t countErrorRuns = 0;
        for (const fs::path &file : allFiles) {
            if (file.string().rfind("__sarif", 0) != std::string::npos) {
                countErrorRuns += 1;
                LOG_S(DEBUG) << file.string() << " - test path";
                json sarifRunFromFile = JsonUtils::getJsonFromFile(file);
                sarif_json["runs"]["results"].push_back(sarifRunFromFile);
            }
        }
        return countErrorRuns;
    }
}
