#include <iostream>
#include <string>

#include "versionInfo.h"

namespace random_left {

    using std::cout, std::endl;

    const std::string app_name    = "random_left_game";
    const VersionInfo app_version = VersionInfo(0, 1, 3, "aazero");
    const std::string app_author  = "allan_walpy";

    void print_about_info () {
        cout << endl;
        cout << app_name << " v" << app_version.stringify() << " created by" << app_author << ";" << endl;
    }
} // namespace random_left
