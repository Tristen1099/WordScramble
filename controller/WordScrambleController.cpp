#include "WordScrambleController.h"

namespace controller
{

const string& WordScrambleController::DICTIONARY_FILE_NAME = "other/dictionary.txt";

WordScrambleController::WordScrambleController()
{
    this->fileReader = new DictionaryFileReader(DICTIONARY_FILE_NAME);
    this->dictionary = this->fileReader->readFileToDictionary();
}

WordScrambleController::~WordScrambleController()
{
    delete this->dictionary;
    delete this->fileReader;
    delete this->validWords;
    delete this->guessedWords;
}


void WordScrambleController::readFileToDictionary(const string& filename)
{
    delete this->dictionary;
    this->dictionary = this->fileReader->readFileToDictionary();
}

bool WordScrambleController::guessWord(const string& word)
{
    bool isAlreadyGuessed = find(this->guessedWords->begin(), this->guessedWords->end(), word) != this->guessedWords->end();
    bool isValid = find(this->validWords->begin(), this->validWords->end(), word) != this->validWords->end();
    return (!isAlreadyGuessed && isValid);
}

void WordScrambleController::makeNewCurrentWordsWith(vector<char> letters)
{
    this->validWords = this->dictionary->findAllWordsContaining(letters);
}

vector<string>* WordScrambleController::getValidWords() const
{
    return this->validWords;
}

vector<string>* WordScrambleController::getGuessedWords() const
{
    return this->guessedWords;
}

void WordScrambleController::resetGame()
{
    this->validWords->clear();
    this->guessedWords->clear();
}


}