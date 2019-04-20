#include "Dictionary.h"

namespace model
{

Dictionary::Dictionary(vector<string> words)
{
    this->words = words;
}

Dictionary::~Dictionary()
{
    //dtor
}

void Dictionary::setCollection(vector<string> newCollection)
{
    this->words = newCollection;
}

vector<string> Dictionary::getCollection()
{
    return this->words;
}

vector<string> Dictionary::findAllWordsContaining(vector<char> letters)
{
    vector<string> output;
    for (size_t i = 0; i < this->words.size(); i++)
    {
        string currentWord = this->words[i];

        if (this->validWord(currentWord, letters))
        {
            cout << currentWord << endl;
            output.push_back(currentWord);
        }
    }
    return output;
}

bool Dictionary::validWord(const string& word, vector<char> letters)
{
    bool valid = true;
    for (size_t i = 0; i < word.size(); i++)
    {
        char currentWordLetter = word.at(i);
        bool validLetter = false;
        for (size_t j = 0; j < letters.size(); j++)
        {
            if (letters[j] == currentWordLetter)
            {
                validLetter = true;
                letters.erase(letters.begin() + j);
                break;
            }
        }



        if (!validLetter)
        {
            valid = false;
            break;
        }

    }
    return valid;







    /*
    bool containsEach = true;
    size_t totalMatches = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        char currentWordLetter = word.at(i);
        bool validLetter = (find(letters.begin(), letters.end(), currentWordLetter) != letters.end());


        if (!validLetter)
        {
            cout << "Invalid: " << word << endl;
            containsEach = false;
            break;
        }

    }
    */


}

}
