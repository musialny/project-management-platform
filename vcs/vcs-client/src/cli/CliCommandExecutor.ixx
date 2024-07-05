module;

#include <string_view>
#include <vector>

export module vcs.client.CliCommandExecutor;

namespace vcs::client::cli {
    export using CommandParameters = std::vector<std::string_view>;
    export struct CliArgs {
        int argc;
        const char* const* const argv;
    };

    export template<size_t offset>
    class CliCommandExecutor {
        std::vector<CommandParameters> commands;
    public:
        explicit CliCommandExecutor(const CliArgs&& args) {
            CommandParameters params;
            for (size_t i = offset; i < args.argc; i++) {
                if (args.argv[i][0] == '-') {
                    commands.emplace_back(params);
                    params.clear();
                }
                params.emplace_back(args.argv[i]);
            }
            if (!params.empty()) commands.emplace_back(params);
        }
    };
}
