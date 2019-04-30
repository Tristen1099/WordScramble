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

            size_t pos = 0;
            string score;
            string timeLimit;
            string date;

            for(int index=0; index<3; index++)
            {
                string token = "";
                pos = line.find(",");
                token = line.substr(0, pos);
                if(index==0)
                {
                    score = token;
                }
                else if(index==1)
                {

                    timeLimit = token;
                }
                else
                {
                    date = token;
                }
                line.erase(0, pos + 1);

            }

            try
            {
                int value = stoi(score);
                HighScore newScore;
                newScore.setHighScore(value);
                newScore.setDate(date);
                newScore.setTimeLimit(timeLimit);
                this->scores.push_back(newScore);
            }
            catch(...)
            {
            }

        }
        myfile.close();
    }

    else cout << "Unable to open/find file: " << this->file << endl;

}

vector<HighScore> HighScoreFileReader::getScores()
{

    return this->scores;

}

}
