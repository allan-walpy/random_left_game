#include <iostream>
#include <string>

#include "versionInfo.hpp"

using std::cout, std::endl;

const std::string app_name    = "random_left_game";
const std::string app_version = "0.2.0-aazero";
const std::string app_author  = "allan_walpy";

void print_about_info () {
    cout << endl;
    cout << app_name << " v" << app_version << " created by" << app_author << ";" << endl;
}
