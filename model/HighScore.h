#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
using namespace std;

namespace model

{


class HighScore
{
          public:
                    HighScore();
                    virtual ~HighScore();
                    int getHighScore();
                    void setHighScore(int score);
                    string getTimeLimit();
                    void setTimeLimit(string time);
                    string getDate();
                    void setDate(string date);


          private:
                    int highScore;
                    string timeLimit;
                    string date;
};

}

#endif // HIGHSCORE_H
