module;

#include <vector>

export module vcs.shared.cli_preprocessor.CliCommandExecutor;

import vcs.shared.cli_preprocessor.CliCommandParameters;
import vcs.shared.cli_preprocessor.CliActionsContainer;

namespace vcs::shared::cli_preprocessor {
    export struct CliArgs {
        int amountOfArguments;
        const char* const* const arguments;
    };

    export class CliCommandExecutor {
        std::vector<CommandParameters> commands;

        [[nodiscard]] ExecutorArguments generateExecutorArguments(
                const std::string_view& command,
                const std::vector<CliActionArgument>& argumentsNames) const {
            ExecutorArguments result;
            result[command] = commands[0];

            for (size_t i = 1; i < commands.size(); i++) {
                for (const auto& [argument, aliases] : argumentsNames) {
                    if (commands[i][0] == argument) {
                        result[argument] = commands[i];
                        break;
                    }
                    bool nestedBreak = false;
                    for (const auto& argumentAlias : aliases)
                        if (commands[i][0] == argumentAlias) {
                            result[argument] = commands[i];
                            nestedBreak = true;
                            break;
                        }
                    if (nestedBreak) break;
                }
            }

            return result;
        }
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
            if (commands[0].empty()) commands[0].emplace_back("");
        }

        int operator()(const CliActionsContainer& actionsContainer) const {
            const auto& actions = actionsContainer.getActions();
            for (const auto& action : actions)
                if (action.command == commands[0][0])
                    return action.executor(generateExecutorArguments(action.command, action.arguments));
            return -1;
        }
    };
}
