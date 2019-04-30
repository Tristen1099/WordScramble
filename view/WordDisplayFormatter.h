#ifndef WORDDISPLAYFORMATTER_H
#define WORDDISPLAYFORMATTER_H

#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

namespace view
{

class WordDisplayFormatter
{
private:
    static const size_t COLUMN_WIDTH = 10;

public:
    static const string format(const vector<string>* guessed, const vector<string>* allWords);


private:
    static const string drawWord(const string& word, const vector<string>* guessed);
};

}

#endif // WORDDISPLAYFORMATTER_H
