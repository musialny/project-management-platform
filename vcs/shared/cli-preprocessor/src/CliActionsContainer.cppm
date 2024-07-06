module;

#include <vector>
#include <initializer_list>

export module vcs.shared.cli_preprocessor.CliActionsContainer;

import vcs.shared.cli_preprocessor.CliCommandExecutor;

namespace vcs::shared::cli_preprocessor {
    export using CliAction = void (*)(const CommandParameters& args);

    export class CliActionsContainer {
        std::vector<CliAction> actions;
    public:
        explicit CliActionsContainer(const std::initializer_list<CliAction>& actionsList) {
            for (const auto& action : actionsList)
                actions.emplace_back(action);
        }
    };
}
