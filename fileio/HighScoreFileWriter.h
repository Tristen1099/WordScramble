#ifndef HIGHSCOREFILEWRITER_H
#define HIGHSCOREFILEWRITER_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


namespace fileio
{

class HighScoreFileWriter
{

public:

    //Creates a HighScoreFileWriter object
    //@precondition none
    //@postcondition Created HighScoreFileWriter object
    HighScoreFileWriter();

    // Destructs the HighScoreFileWriter object when its lifetime ends
    virtual ~HighScoreFileWriter();

    //Writes to the input file
    //@precondition filePath can not be empty
    //@postcondition Created file in system
    void writeToFile(const string filePath, const string output);

};
}

#endif // HIGHSCOREFILEWRITER_H
