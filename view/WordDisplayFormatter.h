#ifndef WORDDISPLAYFORMATTER_H
#define WORDDISPLAYFORMATTER_H

#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;

namespace view
{

class WordDisplayFormatter
{
private:
    static const size_t COLUMN_WIDTH = 10;

public:
    static const string format(const set<string>* guessed, const set<string>* allWords);


private:
    static const string drawWord(const string& word, const set<string>* guessed);
};

}

#endif // WORDDISPLAYFORMATTER_H
