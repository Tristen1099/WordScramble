#include "TrieTree.h"

#include <iostream>
using namespace std;

TrieTree::TrieTree()
{
    this->root = new TrieNode();
}

TrieTree::TrieTree(TrieNode* root)
{
    this->root = root;
}

TrieTree::~TrieTree()
{
    delete this->root;
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

void TrieTree::findAllWordsUsing(char* letters, int letterCount, vector<string>* result)
{
    string* previous = new string("");
    this->findAllWordsUsing(letters, letterCount, previous, result, this->root);
    delete previous;
}

void TrieTree::findAllWordsUsing(char* letters, int letterCount, string* previous, vector<string>* result, TrieNode* root)
{
    TrieNode* pCrawl = root;
    char* changingLetters = letters;
    for (size_t i = 0; i < letterCount; i++)
    {
        char currentLetter = changingLetters[0];
        int childIndex = currentLetter - 'a';
        TrieNode* child = pCrawl->childAt(childIndex);

        if (child != nullptr)
        {
            *previous += currentLetter;
            if (child->isEndOfWord())
            {
                result->push_back(*previous);
            }

            if (letterCount > 0)
            {
                char* nextLevelLetters = createWithoutFirstLetter(changingLetters, letterCount);
                this->findAllWordsUsing(nextLevelLetters, letterCount-1, previous, result, child);
            }
            previous->pop_back();
        }

        changingLetters = this->createShiftedLetters(changingLetters, letterCount);
    }


    /*
    TrieNode* pCrawl = root;
    char* changingLetters = letters;
    for (size_t i = 0; i < letterCount; i++)
    {

        char currentLetter = changingLetters[0];
        int childIndex = currentLetter - 'a';
        if (letterCount == 3)
            cout << "Checking letter at index " << i << " " << currentLetter << " from collection " << changingLetters << endl;
        //cout << "Child index = " << childIndex << endl;

        TrieNode* child = pCrawl->childAt(childIndex);

        if (child != nullptr)
        {
            cout << "Child found" << endl;
            *previous += currentLetter;
            if (child->isEndOfWord())
            {
                result->push_back(*previous);
                cout << "Child is end of word. Pushed \"" << *previous << "\"" << endl;
            }

            if (letterCount > 0)
            {
                char* nextLevelLetters = createWithoutFirstLetter(changingLetters, letterCount);
                cout << "Step into " << currentLetter << endl;
                this->findAllWordsUsing(nextLevelLetters, letterCount-1, previous, result, child);
            }
            previous->pop_back();

        }
        else
        {
            cout << "Not a child" << endl;
        }


        changingLetters = this->createShiftedLetters(changingLetters, letterCount);
    }
    cout << "Step out" << endl;
    */
}

char* TrieTree::createShiftedLetters(char* letters, int letterCount)
{
    char* newLetters = new char[letterCount];

    for (size_t i = 1; i < letterCount; i++)
    {
        newLetters[i] = letters[i-1];
    }
    newLetters[0] = letters[letterCount - 1];

    return newLetters;
}

char* TrieTree::createWithoutFirstLetter(char* letters, int letterCount)
{
    char* newLetters = new char[letterCount-1];

    for (size_t i = 0; i < letterCount; i++)
    {
        newLetters[i] = letters[i+1];
    }

    return newLetters;
}


