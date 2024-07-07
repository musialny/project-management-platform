#include <gtest/gtest.h>
#include <vector>

import vcs.shared.cli_preprocessor.CliCommandExecutor;

using vcs::shared::cli_preprocessor::CliCommandExecutor;
using vcs::shared::cli_preprocessor::CliArgs;
using vcs::shared::cli_preprocessor::CommandParameters;

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
        { "--arg", "1"},
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
