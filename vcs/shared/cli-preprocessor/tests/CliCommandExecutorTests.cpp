#include <gtest/gtest.h>

import vcs.shared.cli_preprocessor.CliCommandExecutor;

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}
