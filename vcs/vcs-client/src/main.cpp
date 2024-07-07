import vcs.shared.cli_preprocessor;

int main(const int argc, const char* argv[]) {
    const vcs::shared::cli_preprocessor::CliActionsContainer actionsContainer {
        [](const vcs::shared::cli_preprocessor::CommandParameters& commandsArray) {

        }
    };

    const vcs::shared::cli_preprocessor::CliCommandExecutor commandExecutor {
        {
            .amountOfArguments = argc,
            .arguments = argv
        }
    };
    return 0;
}
