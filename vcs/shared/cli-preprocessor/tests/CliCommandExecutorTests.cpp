#include <vector>

#include <gtest/gtest.h>

import vcs.shared.cli_preprocessor;

using vcs::shared::cli_preprocessor::CliCommandExecutor;
using vcs::shared::cli_preprocessor::CliActionsContainer;
using vcs::shared::cli_preprocessor::CliArgs;
using vcs::shared::cli_preprocessor::CommandParameters;
using vcs::shared::cli_preprocessor::ExecutorArguments;

class TestableCliCommandExecutor : public CliCommandExecutor {
public:
    explicit TestableCliCommandExecutor(const CliArgs& args)
        : CliCommandExecutor(args) {}

    std::vector<CommandParameters>& getCommands() {
        return *reinterpret_cast<std::vector<CommandParameters>*>(this); // Access private member of CliCommandExecutor
    }
};

TEST(CliCommandExecutor, InternalCommandStructureValidation) {
    constexpr int amountOfArguments {5};
    const char* arguments[] = {
        "commit",
        "--arg", "1",
        "-a", "2",
    };
    const std::vector<CommandParameters> reference {
        {"commit"},
        {"--arg", "1"},
        {"-a", "2"}
    };

    TestableCliCommandExecutor commandExecutor {
        {
                .amountOfArguments = amountOfArguments,
                .arguments = arguments
        }
    };
    const auto commands = commandExecutor.getCommands();

    EXPECT_EQ(reference, commands);
}

TEST(CliCommandExecutor, ExecutorResultValidation) {
    ExecutorArguments commandArguments;
    ExecutorArguments commandArgumentsReference = {
        {"commit", {"commit"}},
        {"--message", {"--message", "Commit", "Message"}}
    };
    const char* commandArgumentsArguments[] = {
        "commit",
        "--message", "Commit", "Message"
    };
    const CliCommandExecutor commandArgumentsCommandExecutor {
            {
                .amountOfArguments = sizeof(commandArgumentsArguments) / sizeof(char*),
                .arguments = commandArgumentsArguments
            }
    };

    const CliActionsContainer commands = {
        {
            {
                .command = "commit",
                .arguments = {
                    {
                        .argument = "--message",
                        .aliases = {"-m", "-M"}
                    }
                },
                .executor = [&](const ExecutorArguments& arguments) -> int {
                    commandArguments = arguments;
                    return 0;
                }
            }
        }
    };

    commandArgumentsCommandExecutor(commands);
    EXPECT_EQ(commandArgumentsReference, commandArguments);
}

TEST(CliCommandExecutor, ExecutorResultAliasValidation) {
    ExecutorArguments commandArguments;
    ExecutorArguments commandArgumentsReference = {
        {"commit", {"commit"}},
        {"--message", {"-m", "Commit", "Message"}}
    };
    const char* commandArgumentsArguments[] = {
        "commit",
        "-m", "Commit", "Message"
    };
    const CliCommandExecutor commandArgumentsCommandExecutor {
        {
            .amountOfArguments = sizeof(commandArgumentsArguments) / sizeof(char*),
            .arguments = commandArgumentsArguments
        }
    };

    const CliActionsContainer commands = {
        {
            {
                .command = "commit",
                .arguments = {
                    {
                        .argument = "--message",
                        .aliases = {"-m", "-M"}
                    }
                },
                .executor = [&](const ExecutorArguments& arguments) -> int {
                    commandArguments = arguments;
                    return 0;
                }
            }
        }
    };

    commandArgumentsCommandExecutor(commands);
    EXPECT_EQ(commandArgumentsReference, commandArguments);
}

TEST(CliCommandExecutor, ExecutorResultEmptyCommandValidation) {
    ExecutorArguments commandArguments;
    ExecutorArguments commandArgumentsReference = {
        {"", {""}},
        {"--version", {"-v", "Random", "Things"}},
        {"--user", {"--user", "John"}}
    };
    const char* commandArgumentsArguments[] = {
        "-v", "Random", "Things",
        "--user", "John"
    };
    const CliCommandExecutor commandArgumentsCommandExecutor {
        {
            .amountOfArguments = sizeof(commandArgumentsArguments) / sizeof(char*),
            .arguments = commandArgumentsArguments
        }
    };

    const CliActionsContainer commands = {
        {
            {
                .command = "",
                .arguments = {
                    {
                        .argument = "--version",
                        .aliases = {"-v", "-V"}
                    },
                    {
                        .argument = "--user",
                        .aliases = {}
                    }
                },
                .executor = [&](const ExecutorArguments& arguments) -> int {
                    commandArguments = arguments;
                    return 0;
                }
            }
        }
    };

    commandArgumentsCommandExecutor(commands);
    EXPECT_EQ(commandArgumentsReference, commandArguments);
}
