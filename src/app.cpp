#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string app_name = "random_left_game";
const string app_version = "0.1.0-zero";
const string app_author = "allan_walpy";

class operation_data
{
public:
    int first;
    int second;

    int answer;

    bool isCorrect()
    {
        return answer == first - second;
    }
};

int main()
{
    string info = app_name + " v" + app_version + " created by " + app_author + " >_> ☭ ";
    info = info.append(";");
    cout << info << endl;

    operation_data data;
    data.first = 13;
    data.second = 27;
    cout << data.first << "-" << data.second << " = ";
    cin >> data.answer;
    cout << (data.isCorrect() ? "correct 👌" : "WRONG!") << endl;

    return 0;
}
