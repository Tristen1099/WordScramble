#include "Utils.h"



string removeWhitespaces(string str)
{
    str.erase(remove_if(str.begin(), str.end(), [](char c){ return isspace(c, cin.getloc());}), str.end());
    return str;
}


