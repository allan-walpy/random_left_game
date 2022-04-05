#include <iostream>
#include <string>

using namespace std;

const string app_name = "random_left_game";
const string app_version = "0.1.0-zero";
const string app_author = "allan_walpy";

int main()
{
    int a = 5 + 5, b = 2713, c;

    cout << a << "-" << b << " = ";
    cin >> c;
    cout << ((c == a - b) ? "correct 👌" : "WRONG!") << endl;

    string info = app_name + " v" + app_version + " created by " + app_author;
    info = info.append(";");
    cout << info << endl;

    return 0;
}
