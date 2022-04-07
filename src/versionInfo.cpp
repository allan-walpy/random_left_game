#include <string>

using namespace std;

class VersionInfo
{
private:
    int _major;
    int _minor;
    int _patch;
    string _appending;

public:
    VersionInfo(int major, int minor, int patch, string appending = "")
    {
        _major = major;
        _minor = minor;
        _patch = patch;
        _appending = appending;
    }

    string toString() const
    {
        return to_string(_major) + "." + to_string(_minor) + "." + to_string(_patch) +
               (_appending == "" ? "" : "-" + _appending);
    }
};
