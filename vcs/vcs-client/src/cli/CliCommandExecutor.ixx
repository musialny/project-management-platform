module;

#include <string_view>
#include <vector>

export module vcs.client.CliCommandExecutor;

namespace vcs::client::cli {
    export using CommandsArray = std::vector<std::string_view>;
    export struct CliArgs {
        int argc;
        const char* const* const argv;
    };

    export template<size_t offset>
    class CliCommandExecutor {
        CommandsArray rawCommands;
    public:
        explicit CliCommandExecutor(const CliArgs&& args) {
            for (size_t i = offset; i < args.argc; i++)
                rawCommands.emplace_back(args.argv[i]);
        }
    };
}
