#include <iostream>
#include <string>

using std::cout, std::endl;

const std::string kAppName    = "random_left_game";
const std::string kAppVersion = "0.2.0-aazero";
const std::string kAppAuthor  = "allan_walpy";

void PrintAboutInfo () {
    cout << endl;
    cout << kAppName << " v" << kAppVersion << " created by" << kAppAuthor << ";" << endl;
}
