#include "Dictionary.h"

#include <iostream>
using namespace std;

namespace model
{

Dictionary::Dictionary(vector<string> words)
{
    for (size_t i = 0; i < words.size(); i++)
    {
        this->wordTree.insert(words.at(i));
    }
}

Dictionary::~Dictionary()
{
    //dtor
}

void Dictionary::setCollection(vector<string> newCollection)
{
    for (size_t i = 0; i < newCollection.size(); i++)
    {
        this->wordTree.insert(newCollection.at(i));
    }
}

vector<string>* Dictionary::findAllWordsContaining(vector<char> letters)
{
    vector<string>* validWords = new vector<string>();
    size_t letterCount = letters.size();
    char* charLetters = new char[letterCount];
    copy(letters.begin(), letters.end(), charLetters);


    this->wordTree.findAllWordsUsing(charLetters, letterCount, validWords);
    delete charLetters;
    sort( validWords->begin(), validWords->end() );
    validWords->erase( unique( validWords->begin(), validWords->end() ), validWords->end() );
    /*
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
    */
    return validWords;
}

bool Dictionary::validWord(const string& word, vector<char> letters)
{
    /*
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
    */

}

}
