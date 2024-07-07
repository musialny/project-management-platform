module;

#include <vector>
#include <string_view>

export module vcs.shared.cli_preprocessor.CliCommandParameters;

namespace vcs::shared::cli_preprocessor {
    export using CommandParameters = std::vector<std::string_view>;
}
