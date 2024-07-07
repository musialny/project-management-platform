module;

#include <string_view>
#include <vector>

export module vcs.shared.cli_preprocessor.CliCommandExecutor;

namespace vcs::shared::cli_preprocessor {
    export using CommandParameters = std::vector<std::string_view>;
    export struct CliArgs {
        int amountOfArguments;
        const char* const* const arguments;
    };

    export class CliCommandExecutor {
        std::vector<CommandParameters> commands;
    public:
        explicit CliCommandExecutor(const CliArgs& args) {
            CommandParameters params;
            for (size_t i = 0; i < args.amountOfArguments; i++) {
                if (args.arguments[i][0] == '-') {
                    commands.emplace_back(params);
                    params.clear();
                }
                params.emplace_back(args.arguments[i]);
            }
            if (!params.empty()) commands.emplace_back(params);
        }
    };
}
