#pragma execution_character_set("utf-8")

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

const string app_name = "random_left_game";
const string app_version = "0.1.0-zero";
const string app_author = "allan_walpy";

int main()
{
    string info = app_name + " v" + app_version + " created by " + app_author + " >_> ☭ ";
    info = info.append(";");
    cout << info << endl;

    ofstream info_file("info.txt");
    info_file << info << endl;
    info_file.close();

    return 0;
}
