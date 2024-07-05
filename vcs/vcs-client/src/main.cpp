import vcs.client.cli;

int main(int argc, const char* argv[]) {
    vcs::client::cli::CliActionsContainer actionsContainer {
        [](const vcs::client::cli::CommandsArray& commandsArray) {

        }
    };

    vcs::client::cli::CliCommandExecutor<1> commandExecutor {
        {argc, argv}
    };
    return 0;
}
