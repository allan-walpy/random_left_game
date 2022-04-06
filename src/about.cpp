#include <string>

const std::string app_name = "random_left_game";
const std::string app_version = "0.1.1-zero";
const std::string app_author = "allan_walpy";

std::string get_about_information_string()
{
    return app_name + " v" + app_version + " created by " + app_author + ";";
}
