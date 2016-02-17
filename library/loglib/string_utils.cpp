#include <loglib/string_utils.h>


namespace loglibns {
    
    std::vector<std::string> split_string(const std::string& str,
                                          const std::string& delimiter)
    {
        std::vector<std::string> strings;
        
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delimiter, prev)) != std::string::npos)
        {
            strings.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        
        // To get the last substring (or only, if delimiter is not found)
        strings.push_back(str.substr(prev));
        
        return strings;
    }
    
    
    std::string string_replace( std::string src, std::string const& target, std::string const& repl)
    {
        // handle error situations/trivial cases

        if (target.length() == 0) {
            // searching for a match to the empty string will result in 
            //  an infinite loop
            //  it might make sense to throw an exception for this case
            return src;
        }

        if (src.length() == 0) {
            return src;  // nothing to match against
        }

        size_t idx = 0;

        for (;;) {
            idx = src.find( target, idx);
            if (idx == std::string::npos)  break;

            src.replace( idx, target.length(), repl);
            idx += repl.length();
        }

        return src;
    }
}