#include <iostream>

#include "about_info.h"

//!! >_> i am learning c++, go away <_<;

using std::cin, std::cout, std::endl;

/**
 * @brief program entry point
 *
 * @return int
 */
auto main () -> int {
    cout << "program://launch" << endl;

    int x;
    cout << x << endl;

    PrintAboutInfo();
    cout << "program://shutdon --input any_key - ";
    cin.get();
    return 0;
}
