#include "HighScoreFileReader.h"

namespace fileio
{

HighScoreFileReader::HighScoreFileReader(string& file):file(file)
{
    //ctor
}

HighScoreFileReader::~HighScoreFileReader()
{
    //dtor
}

void HighScoreFileReader::loadFile()
{
    string line;
    ifstream myfile (this->file);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {



        }
        myfile.close();
    }

    else cout << "Unable to open/find file: " << this->file << endl;

}

vector<string> HighScoreFileReader::getScores()
{

    return this->scores;

}

}
