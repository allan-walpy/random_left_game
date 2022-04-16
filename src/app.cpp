#include <iostream>
#include "about.h"

using std::cin, std::cout, std::endl;

/**
 * @brief program entry point
 *
 * @return int
 */
auto main() -> int
{
    cout << "program://launch" << endl;

    print_about_info();
    cin.get();
    return 0;
}
