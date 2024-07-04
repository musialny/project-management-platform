module;

#include <string_view>
#include <vector>

export module vcs.client.cli;

namespace vcs::client::cli {
    export template<size_t offset>
    class CliCommandExecutor {
        std::vector<std::string_view> rawCommands;
    public:
        CliCommandExecutor(int argc, const char* argv[]) {
            for (size_t i = offset; i < argc; i++)
                rawCommands.emplace_back(argv[i]);
        }
    };
}
