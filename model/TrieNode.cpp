#include "TrieNode.h"

namespace model
{

TrieNode::TrieNode()
{
    this->isLeaf = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        this->children[i] = nullptr;
    }
}

TrieNode::~TrieNode()
{
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        delete this->children[i];
    }
}

bool TrieNode::isEndOfWord()
{
    return this->isLeaf;
}

TrieNode* TrieNode::childAt(int index)
{
    return this->children[index];
}

void TrieNode::createChildAt(int index)
{
    this->children[index] = new TrieNode();
}

void TrieNode::setIsEndOfWord(bool value)
{
    this->isLeaf = value;
}

}
