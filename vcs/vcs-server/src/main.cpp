import vcs.shared.cli_preprocessor;
import vcs.server.commands;

using vcs::shared::cli_preprocessor::CliCommandExecutor;
using vcs::shared::cli_preprocessor::CliActionsContainer;
using vcs::server::commands::Version;

int main(const int argc, const char* argv[]) {
    const CliCommandExecutor commandExecutor {
            {
                .amountOfArguments = argc - 1,
                .arguments = argv + 1
            }
    };

    return commandExecutor(CliActionsContainer {
        {
            Version
        }
    });
}
