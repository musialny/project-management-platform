import vcs.shared.cli_preprocessor;

int main(const int argc, const char* argv[]) {
    vcs::shared::cli_preprocessor::CliActionsContainer actionsContainer {
        [](const vcs::shared::cli_preprocessor::CommandParameters& commandsArray) {

        }
    };

    vcs::shared::cli_preprocessor::CliCommandExecutor<1> commandExecutor {
        {argc, argv}
    };
    return 0;
}
