#ifndef WORDDISPLAYFORMATTER_H
#define WORDDISPLAYFORMATTER_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

class WordDisplayFormatter
{
    public:
        static string format(vector<string>* guessed, vector<string>* allWords);


    private:
        static string drawWord(const string& word, vector<string>* guessed);
};

#endif // WORDDISPLAYFORMATTER_H
