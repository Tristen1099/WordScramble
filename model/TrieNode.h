#ifndef TRIENODE_H
#define TRIENODE_H

#include "../utilities/Utils.h"

namespace model
{

class TrieNode
{
private:
    bool isLeaf;
    TrieNode* children[ALPHABET_SIZE];

public:

    //
    // Node used for Trietree
    //
    // @precondition none
    // @postcondition none
    //
    TrieNode();

    //
    // Destructs node
    //
    // @precondition none
    // @postcondition all objects are deleted
    //
    virtual ~TrieNode();

    //
    // Says whether node is a leaf of not
    //
    // @precondition none
    // @postcondition none
    //
    // @return true if leaf
    //
    bool isEndOfWord();

    //
    // gets child at the given index
    //
    // @precondition none
    // @postcondition none
    //
    // @param index the index
    //
    // @return true the child at the index
    //
    TrieNode* childAt(int index);

    //
    // Creates a child at the given index
    //
    // @precondition none
    // @postcondition none
    //
    // @param index the index
    //
    void createChildAt(int index);

    //
    // Sets whether node is a leaf
    //
    // @precondition none
    // @postcondition node is a leaf if value is true
    //
    // @param value whether node is set to a leaf
    //
    void setIsEndOfWord(bool value);

};

}
#endif // TRIENODE_H
