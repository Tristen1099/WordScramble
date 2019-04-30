#include "WordDisplayFormatter.h"

namespace view
{

const string WordDisplayFormatter::format(const set<string>* guessed, const set<string>* allWords)
{
    stringstream sstream;

    size_t maxForloop = allWords->size() - allWords->size()%3;
    for (size_t i = 0; i < maxForloop; i+=3)
    {
            sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(), i+0), guessed);
        sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(), i+1), guessed);
        sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(), i+2), guessed);
            sstream << endl;
    }

    if (allWords->size()-maxForloop == 1)
    {
        sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(),maxForloop+0), guessed);
        sstream << endl;
    }
    else if (allWords->size()-maxForloop == 2)
    {
        sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(),maxForloop+0), guessed);
        sstream << setw(COLUMN_WIDTH) << left << drawWord(*std::next(allWords->begin(),maxForloop+1), guessed);
        sstream << endl;
    }


    return sstream.str();
}

const string WordDisplayFormatter::drawWord(const string& word, const set<string>* guessed)
{
    string output;
    bool isGuessed = find(guessed->begin(), guessed->end(), word) != guessed->end();
    if(isGuessed)
    {
        output = word;
    }
    else
    {
        output = string(word.size(), '#');
    }
    return output;
}
}
