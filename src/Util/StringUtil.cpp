#include "StringUtil.h"

namespace StringUtil
{
    std::vector<std::string> splitString(std::string str, char delimiter)
    {
        std::vector<std::string> internal;
        std::stringstream ss(str);
        std::string tok;

        while(std::getline(ss, tok, delimiter))
        {
            internal.push_back(tok);
        }

        return internal;
    }

    unsigned int countOccurences(std::string s, char c)
    {
        unsigned int t = 0;
        const char * cstr = s.c_str();
        for (unsigned int i = 0; i < s.length(); i++)
        {
            if (cstr[i] == c)
                t++;
        }
        return t;
    }
}
