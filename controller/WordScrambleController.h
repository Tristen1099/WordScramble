#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include "../model/Dictionary.h"
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
    vector<string> guessedWords;
    vector<string> validWords;

public:
    WordScrambleController();
    virtual ~WordScrambleController();

    void readFileToDictionary(const string& filename);
    bool guessWord(const string& word);
    void makeNewCurrentWordsWith(vector<char> letters);

    vector<string> getValidWords();
    vector<string> getGuessedWords();

    void resetGame();


private:
    void clearValidWords();
    void clearGuessedWords();

};
}

#endif // WORDSCRAMBLECONTROLLER_H
