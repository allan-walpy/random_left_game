#include <iostream>

#include "about.hpp"

//!! >_> i am learning c++, go away <_<;

using std::cin, std::cout, std::endl;

/**
 * @brief program entry point
 *
 * @return int
 */
auto main () -> int {
    cout << "program://launch" << endl;

    print_about_info();
    cin.get();
    return 0;
}
