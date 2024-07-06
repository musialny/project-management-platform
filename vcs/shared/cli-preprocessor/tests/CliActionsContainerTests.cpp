#include <gtest/gtest.h>

import vcs.shared.cli_preprocessor.CliActionsContainer;

TEST(HelloTest2, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}
