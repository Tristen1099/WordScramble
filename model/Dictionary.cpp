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

void Dictionary::setCollection(vector<string> newCollection)
{
    this->wordTree.clear();
    for (size_t i = 0; i < newCollection.size(); i++)
    {
        this->wordTree.insert(newCollection.at(i));
    }
}

set<string>* Dictionary::findAllWordsContaining(vector<char> letters)
{
    set<string>* validWords = new set<string>();
    size_t letterCount = letters.size();
    char* charLetters = new char[letterCount];
    copy(letters.begin(), letters.end(), charLetters);


    this->wordTree.findAllWordsUsing(charLetters, letterCount, validWords);
    delete charLetters;
    //sort(validWords->begin(), validWords->end());
    //validWords->erase(unique( validWords->begin(), validWords->end() ), validWords->end());

    return validWords;
}

}
