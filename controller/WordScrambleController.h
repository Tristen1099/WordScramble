#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include "../model/Dictionary.h"
#include "../model/RandomLetterGenerator.h"
using namespace model;

#include "../fileio/DictionaryFileReader.h"
using namespace fileio;

namespace controller
{

class WordScrambleController
{
private:
    static const string& DICTIONARY_FILE_NAME;

    Dictionary* dictionary;
    DictionaryFileReader* fileReader;
    set<string>* guessedWords;
    set<string>* validWords;

public:
    WordScrambleController();
    virtual ~WordScrambleController();

    void readFileToDictionary(const string& filename);
    bool guessWord(const string& word);
    void setValidWordsWith(vector<char> letters);

    set<string>* getValidWords() const;
    set<string>* getGuessedWords() const;
    vector<char> getRandomLetters(size_t letterCount);

    void resetGame();



};
}

#endif // WORDSCRAMBLECONTROLLER_H
