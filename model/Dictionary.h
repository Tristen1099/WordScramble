#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


namespace model
{

class Dictionary
{

private:
    vector<string> words;

public:
    Dictionary(vector<string> words);
    virtual ~Dictionary();

    void setCollection(vector<string> newCollection);
    vector<string> getCollection();

    vector<string> findAllWordsContaining(vector<char> letters);

private:
    bool wordContainsEachLetter(const string& word, vector<char> letters);
    bool validWord(const string& word, vector<char> letters);
};

}

#endif // DICTIONARY_H
