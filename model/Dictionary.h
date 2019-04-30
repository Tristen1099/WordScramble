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
    TrieTree wordTree;

public:
    Dictionary(vector<string> words);

    void setCollection(vector<string> newCollection);
    set<string>* findAllWordsContaining(vector<char> letters);

private:
    bool wordContainsEachLetter(const string& word, vector<char> letters);
};

}

#endif // DICTIONARY_H
