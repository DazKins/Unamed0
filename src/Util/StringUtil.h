#ifndef STRINGUTIL_H_INCLUDED
#define STRINGUTIL_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>

namespace StringUtil
{
    std::vector<std::string> splitString(std::string str, char delimiter);
}

#endif // STRINGUTIL_H_INCLUDED
