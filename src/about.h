#pragma once

#include <string>
#include "versionInfo.cpp"

const std::string app_name = "random_left_game";
const VersionInfo app_version = VersionInfo(0, 1, 2, "aazero");
const std::string app_author = "allan_walpy";
const std::string app_footer = app_name + " v" + app_version.toString() + " created by " + app_author + ";";

void print_copyright()
{
    cout << endl << app_footer << endl;
}
