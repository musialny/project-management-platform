module;

#include <iostream>

export module core;

namespace core {
    export void hello_there() {
        std::cout << "VCS Client";
    }
}
