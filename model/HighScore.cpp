#include "HighScore.h"

namespace model
{

HighScore::HighScore()
{
    this->highScore = 0;
    this->date = "";
    this->timeLimit = "";
}

HighScore::~HighScore()
{
    //dtor
}

int HighScore::getHighScore()
{
    return this->highScore;
}

void HighScore::setHighScore(int score)
{
    this->highScore = score;
}

string HighScore::getTimeLimit()
{
    return this->timeLimit;
}

void HighScore::setTimeLimit(string time)
{
    this->timeLimit = time;
}

string HighScore::getDate()
{
    return this->date;
}

void HighScore::setDate(string date)
{
    this->date = date;
}

}
