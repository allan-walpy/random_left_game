#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string app_name = "random_left_game";
const string app_version = "0.1.0-zero";
const string app_author = "allan_walpy";

class OperationData
{
private:
    int _first;
    int _second;

public:
    int answer;

    OperationData(int in_first, int in_second)
    {
        _first = in_first;
        _second = in_second;
    }

    string getQuestion()
    {
        return to_string(_first) + "-" + to_string(_second);
    }

    bool isCorrect()
    {
        return answer == _first - _second;
    }
};

int main()
{
    string info = app_name + " v" + app_version + " created by " + app_author + " >_> ☭ ";
    info = info.append(";");
    cout << info << endl;

    OperationData data(13, 27);
    cout << data.getQuestion() << " = ";
    cin >> data.answer;
    cout << (data.isCorrect() ? "correct 👌" : "WRONG!") << endl;

    return 0;
}
