#include <string>

namespace random_left {

    using std::string;

    class VersionInfo {
        public:

        VersionInfo(int, int, int, string = "");

        /**
         * @brief stringifies version
         *
         * @return string
         */
        [[nodiscard]] auto stringify() const -> string;
    };

} // namespace random_left
