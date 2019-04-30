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

    //
    // Holds the words in a tree for easy lookups
    //
    // @precondition none
    // @postcondition words are stored
    //
    // @param words the words held in the tree
    //
    Dictionary(vector<string> words);

    //
    // Sets the tree to hold the given collection
    //
    // @precondition none
    // @postcondition words are stored
    //
    // @param newCollection the words held in the tree
    //
    void setCollection(vector<string> newCollection);

    //
    // Finds all words containing the given letters
    //
    // @precondition none
    // @postcondition none
    //
    // @param letters the letters used
    //
    set<string>* findAllWordsContaining(vector<char> letters);

private:
    bool wordContainsEachLetter(const string& word, vector<char> letters);
};

}

#endif // DICTIONARY_H
