#include <iostream>

#include "about_info.h"

//!! >_> i am learning c++, go away <_<;

using std::cin, std::cout, std::endl;

int exit();

auto main () -> int {
    cout << "program://launch" << endl;

    int input;
    cout << input << endl;

    return exit();
}

auto exit () -> int {
    PrintAboutInfo();
    cout << "program://shutdon --input any_key - ";
    cin.get();
    return 0;
}
