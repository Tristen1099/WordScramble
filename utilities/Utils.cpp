#include "Utils.h"


string removeWhitespaces(string str)
{
    str.erase(remove_if(str.begin(), str.end(), [](char c)
    {
        return isspace(c, cin.getloc());
    }), str.end());
    return str;
}

void playWow()
{
    const int wowFileCount = 6;
    int fileNumber = rand() % wowFileCount;

    stringstream command;
    command << "/usr/bin/cvlc \"sounds/wow" << fileNumber << ".mp3\" --play-and-exit";
    system(command.str().c_str());
}



