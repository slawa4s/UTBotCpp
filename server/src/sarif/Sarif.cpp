#include "Sarif.h"
#include "utils/JsonUtils.h"
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
        JsonUtils::writeJsonToFile(jsonPath, sarif_json);
    }
}