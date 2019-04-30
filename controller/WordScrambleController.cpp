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
}


void WordScrambleController::readFileToDictionary(const string& filename)
{
    delete this->dictionary;
    this->dictionary = this->fileReader->readFileToDictionary();
}

bool WordScrambleController::guessWord(const string& word)
{
    return false;
}

void WordScrambleController::makeNewCurrentWordsWith(vector<char> letters)
{

}

vector<string> WordScrambleController::getValidWords()
{
    return this->validWords;
}

vector<string> WordScrambleController::getGuessedWords()
{
    return this->guessedWords;
}

void WordScrambleController::resetGame()
{

}

void WordScrambleController::clearValidWords()
{

}

void WordScrambleController::clearGuessedWords()
{

}


}
