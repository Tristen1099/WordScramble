#include "TrieTree.h"

TrieTree::TrieTree()
{
    this->root = new TrieNode();
}

TrieTree::~TrieTree()
{
    delete this->root;
}

bool TrieTree::search(const string& key)
{
    TrieNode* pCrawl = this->root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->childAt(index))
        {
            return false;
        }

        pCrawl = pCrawl->childAt(index);
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord());
}

void TrieTree::insert(const string& key)
{
    TrieNode *pCrawl = this->root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->childAt(index))
        {
            pCrawl->createChildAt(index);
        }

        pCrawl = pCrawl->childAt(index);
    }

    pCrawl->setIsEndOfWord(true);
}


