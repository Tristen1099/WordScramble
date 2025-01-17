#include "WordScrambleController.h"

namespace controller
{

const string& WordScrambleController::DICTIONARY_FILE_NAME = "other/dictionary.txt";

WordScrambleController::WordScrambleController()
{
    this->fileReader = new DictionaryFileReader(DICTIONARY_FILE_NAME);
    this->dictionary = this->fileReader->readFileToDictionary();
    this->guessedWords = new set<string>();
    this->validWords = new set<string>();
}

WordScrambleController::~WordScrambleController()
{
    delete this->dictionary;
    delete this->fileReader;
    delete this->validWords;
    delete this->guessedWords;
}


void WordScrambleController::readFileToDictionary()
{
    delete this->dictionary;
    this->dictionary = this->fileReader->readFileToDictionary();
}

bool WordScrambleController::guessWord(const string& word)
{
    bool isAlreadyGuessed = find(this->guessedWords->begin(), this->guessedWords->end(), word) != this->guessedWords->end();
    bool isValid = find(this->validWords->begin(), this->validWords->end(), word) != this->validWords->end();
    bool correct = (!isAlreadyGuessed && isValid);
    if (correct)
    {
        this->guessedWords->insert(word);
    }
    return correct;
}

void WordScrambleController::setValidWordsWith(vector<char> letters)
{
    delete this->validWords;
    this->validWords = this->dictionary->findAllWordsContaining(letters);
}

set<string>* WordScrambleController::getValidWords() const
{
    return this->validWords;
}

set<string>* WordScrambleController::getGuessedWords() const
{
    return this->guessedWords;
}

vector<char> WordScrambleController::getRandomLetters(size_t letterCount)
{
    return RandomLetterGenerator::makeRandomLetterCollection(letterCount);
}

void WordScrambleController::resetGame()
{
    this->validWords->clear();
    this->guessedWords->clear();
}


}
