#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include "../model/TrieTree.h"


namespace model
{

class Dictionary
{

private:
    //vector<string> words;
    TrieTree wordTree;

public:
    Dictionary(vector<string> words);
    virtual ~Dictionary();

    void setCollection(vector<string> newCollection);
    vector<string>* findAllWordsContaining(vector<char> letters);

private:
    bool wordContainsEachLetter(const string& word, vector<char> letters);
};

}

#endif // DICTIONARY_H
