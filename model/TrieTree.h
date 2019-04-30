#ifndef TRIETREE_H
#define TRIETREE_H

#include "../model/TrieNode.h"
using namespace model;

#include <bits/stdc++.h>
using namespace std;

namespace model
{

//
// TrieTree which was designed to hold a collection of chars
//
class TrieTree
{
private:
    TrieNode* root;

public:

    //
    // Creates a TrieTree which holds a root node
    //
    // @precondition none
    // @postcondition root is set to a new node
    //
    TrieTree();

    //
    // Creates a TrieTree which holds takes the given node to hold as the root
    //
    // @precondition root != null
    // @postcondition root is held as the root
    //
    // @param root the node to be used as the root
    //
    TrieTree(TrieNode* root);

    //
    // Destroys the TrieTree by deleting the head node which will recursively delete all nodes in the tree
    //
    // @precondition none
    // @postcondition all nodes deleted
    //
    virtual ~TrieTree();

    //
    // Removes all nodes from the tree and starts over with only a root
    //
    // @precondition none
    // @postcondition all nodes removed except root
    //
    void clear();

    //
    // Searches the tree for the given string
    //
    // @precondition none
    // @postcondition none
    //
    // @param key the word searched for
    //
    // @return true if tree contains word
    //
    bool search(const string& key);

    //
    // Inserts the word to the tree
    //
    // @precondition none
    // @postcondition none
    //
    // @param key the word inserted for
    //
    void insert(const string& key);

    //
    // Finds all words using the given data
    //
    // @precondition none
    // @postcondition none
    //
    // @param letters the letters used
    // @param letterCount the letter count
    // @param result where the results are inserted
    //
    void findAllWordsUsing(char* letters, int letterCount, set<string>* result);


private:
    void findAllWordsUsing(char* letters, int letterCount, string* previous, set<string>* result, TrieNode* root);
    char* createShiftedLetters(char* letters, int letterCount);
    char* createWithoutFirstLetter(char* letters, int letterCount);
};
}

#endif // TRIETREE_H
