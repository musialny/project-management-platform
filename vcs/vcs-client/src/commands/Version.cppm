module;

#include <iostream>

export module vcs.client.commands.Version;

#ifndef VCS_VERSION
#define VCS_VERSION "VERSION WAS NOT SPECIFIED"

#endif

import vcs.shared.cli_preprocessor;

using vcs::shared::cli_preprocessor::ExecutorArguments;
using vcs::shared::cli_preprocessor::CliAction;

namespace vcs::client::commands {
    export const CliAction Version {
        .command = "",
        .arguments = {
            {
                .argument = "--version",
                .aliases = {"-v", "-V"}
            }
        },
        .executor = [](const ExecutorArguments& arguments) {
            std::cout << "Version: " << VCS_VERSION << std::endl;
            return 0;
        }
    };
}
