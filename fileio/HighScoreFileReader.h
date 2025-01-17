#ifndef HIGHSCOREFILEREADER_H
#define HIGHSCOREFILEREADER_H

#include <vector>
#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../model/HighScore.h"
using namespace model;

namespace fileio
{

class HighScoreFileReader
{
public:

    //Creates a HighScoreFileReader object
    //@precondition none
    //@postcondition Created HighScoreFileReader object
    HighScoreFileReader(string& file);

    // Destructs the HighScoreFileReader object when its lifetime ends
    virtual ~HighScoreFileReader();

    //Loads the file in this-> file
    //@precondition none
    //@postcondition none
    void loadFile();

    //Returns the vector of scores from the loaded file
    //@precondition none
    //@postcondition none
    vector<HighScore> getScores();


private:

    string file;
    vector<HighScore> scores;
};

}

#endif // HIGHSCOREFILEREADER_H
