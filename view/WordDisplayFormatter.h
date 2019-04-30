#ifndef WORDDISPLAYFORMATTER_H
#define WORDDISPLAYFORMATTER_H

#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;

namespace view
{

//
// Formats the given words to the style needed for the output summary
//
class WordDisplayFormatter
{
private:
    static const size_t COLUMN_WIDTH = 14;

public:

    //
    // Formats the words so that only the guessed words are shown and the rest are #
    //
    // @precondition none
    // @postcondition none
    //
    // @param guessed the guessed words
    // @param allWords the total collection of possible words
    //
    // @return the summary string formatted
    //
    static const string format(const set<string>* guessed, const set<string>* allWords);


private:
    static const string drawWord(const string& word, const set<string>* guessed);
};

}

#endif // WORDDISPLAYFORMATTER_H
