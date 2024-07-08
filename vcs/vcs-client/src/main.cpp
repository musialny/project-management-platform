#include <iostream>

import vcs.shared.cli_preprocessor;

using vcs::shared::cli_preprocessor::ExecutorArguments;
using vcs::shared::cli_preprocessor::CliCommandExecutor;
using vcs::shared::cli_preprocessor::CliActionsContainer;

int main(const int argc, const char* argv[]) {
    const CliCommandExecutor commandExecutor {
        {
            .amountOfArguments = argc - 1,
            .arguments = argv + 1
        }
    };

    return commandExecutor(CliActionsContainer {
        {
            {
                .command = "commit",
                .arguments {
                    {
                        .argument = "--message",
                        .aliases {"-m", "-M"}
                    }
                },
                .executor = [](const ExecutorArguments& arguments) {
                    std::cout << "Hello There" << std::endl;
                    return 0;
                }
            }
        }
    });
}
