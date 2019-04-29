#ifndef TRIETREE_H
#define TRIETREE_H

#include "../model/TrieNode.h"

#include <bits/stdc++.h>
using namespace std;

class TrieTree
{
private:
    TrieNode* root;

public:
    TrieTree();
    virtual ~TrieTree();

    bool search(const string& key);
    void insert(const string& key);


private:
};

#endif // TRIETREE_H
