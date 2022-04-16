#include <string>

using std::string, std::to_string;

class VersionInfo {
   private:
    int _major;
    int _minor;
    int _patch;
    string _appending;

   public:
    VersionInfo(int major, int minor, int patch, string appending = "")
        : _major(major), _minor(minor), _patch(patch), _appending(move(appending)) {}

    /**
     * @brief stringifies version
     *
     * @return string
     */
    [[nodiscard]] auto toString() const -> string {
        return to_string(_major) + "." + to_string(_minor) + "." + to_string(_patch) + (empty(_appending) ? _appending : "-" + _appending);
    }
};
