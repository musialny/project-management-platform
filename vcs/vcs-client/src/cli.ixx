module;

#include <string_view>
#include <vector>
#include <initializer_list>

export module vcs.client.cli;

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

    export using CliAction = void (*)(const CommandsArray& args);

    export class CliActionsContainer {
        std::vector<CliAction> actions;
    public:
        explicit CliActionsContainer(std::initializer_list<CliAction> actionsList) {
            for (const auto& action : actionsList)
                actions.emplace_back(action);
        }
    };
}
