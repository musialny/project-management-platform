import vcs.client.cli;

int main(int argc, const char* argv[]) {
    vcs::client::cli::CliCommandExecutor<1> commandExecutor { argc, argv };
    return 0;
}
