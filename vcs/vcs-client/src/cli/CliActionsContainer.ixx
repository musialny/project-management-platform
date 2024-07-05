module;

#include <string_view>
#include <vector>
#include <initializer_list>

export module vcs.client.CliActionsContainer;

import vcs.client.CliCommandExecutor;

namespace vcs::client::cli {
    export using CliAction = void (*)(const CommandParameters& args);

    export class CliActionsContainer {
        std::vector<CliAction> actions;
    public:
        explicit CliActionsContainer(std::initializer_list<CliAction> actionsList) {
            for (const auto& action : actionsList)
                actions.emplace_back(action);
        }
    };
}
