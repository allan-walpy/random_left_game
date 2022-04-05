#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string app_name = "random_left_game";
const string app_version = "0.1.0-zero";
const string app_author = "allan_walpy";

int main()
{

    string info = app_name + " v" + app_version + " created by " + app_author + " >_> ☭ ";
    info = info.append(";");
    cout << info << endl;
    cout << info.length() << " vs " << info.size() << endl;

    cout << sqrt(2713);

    for (int i = 0; i <= 2713; i++)
    {
        double sqrt_result = sqrt(i);
        if (sqrt_result < 43 && sqrt_result > 41)
        {
            cout << " i = " << i << "; sqrt = " << sqrt_result << endl;
        }
    }

    int a = 5 + 5, b = 2713, c;

    cout << a << "-" << b << " = ";
    cin >> c;
    cout << ((c == a - b) ? "correct 👌" : "WRONG!") << endl;

    return 0;
}
