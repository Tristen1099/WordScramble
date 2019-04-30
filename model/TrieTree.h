#ifndef TRIETREE_H
#define TRIETREE_H

#include "../model/TrieNode.h"
using namespace model;

#include <bits/stdc++.h>
using namespace std;

namespace model
{
class TrieTree
{
private:
    TrieNode* root;

public:
    TrieTree();
    TrieTree(TrieNode* root);
    virtual ~TrieTree();

    bool search(const string& key);
    void insert(const string& key);
    void findAllWordsUsing(char* letters, int letterCount, vector<string>* result);


private:
    void findAllWordsUsing(char* letters, int letterCount, string* previous, vector<string>* result, TrieNode* root);
    char* createShiftedLetters(char* letters, int letterCount);
    char* createWithoutFirstLetter(char* letters, int letterCount);
};
}

#endif // TRIETREE_H
