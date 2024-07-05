import vcs.client.Cli;

int main(const int argc, const char* argv[]) {
    vcs::client::cli::CliActionsContainer actionsContainer {
        [](const vcs::client::cli::CommandParameters& commandsArray) {

        }
    };

    vcs::client::cli::CliCommandExecutor<1> commandExecutor {
        {argc, argv}
    };
    return 0;
}
