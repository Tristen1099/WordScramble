#include "WordDisplayFormatter.h"


string WordDisplayFormatter::format(vector<string>* guessed, vector<string>* allWords)
{
    stringstream sstream;

    for (size_t i = 0; i < allWords->size(); i+=3)
    {
        sstream << setw(10) << left << drawWord(allWords->at(i+0), guessed);
        sstream << setw(10) << left << drawWord(allWords->at(i+1), guessed);
        sstream << setw(10) << right << drawWord(allWords->at(i+2), guessed);
        sstream << endl;
    }
    string output = sstream.str();
    delete sstream;

    return output;
}

string WordDisplayFormatter::drawWord(const string& word, vector<string>* guessed)
{
    string output;
    bool isGuessed = find(guessed->begin(), guessed->end(), word) != guessed->end();
    if(isGuessed)
    {
        output = word;
    }
    else
    {
        output = string(word.size(), '*');
    }
    return output;
}
