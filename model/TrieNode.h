#ifndef TRIENODE_H
#define TRIENODE_H

#include "../utilities/Utils.h"

class TrieNode
{
private:
    bool isLeaf;
    TrieNode* children[ALPHABET_SIZE];

public:
    TrieNode();
    virtual ~TrieNode();

    bool isEndOfWord();
    TrieNode* childAt(int index);
    void createChildAt(int index);
    void setIsEndOfWord(bool value);

};

#endif // TRIENODE_H
