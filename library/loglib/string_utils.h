#ifndef LOGLIB_STRING_UTILS
#define LOGLIB_STRING_UTILS

#include <string>
#include <vector>

namespace loglibns {
    std::string string_replace( std::string src, std::string const& target, std::string const& repl);
    std::vector<std::string> split_string(const std::string& str, const std::string& delimiter);
}
#endif