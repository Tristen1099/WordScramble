#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include "../model/Dictionary.h"
#include "../model/RandomLetterGenerator.h"
using namespace model;

#include "../fileio/DictionaryFileReader.h"
using namespace fileio;

namespace controller
{

//
// Main controller for the application
// @author Jacob Slattery
//
class WordScrambleController
{
private:
    static const string& DICTIONARY_FILE_NAME;

    Dictionary* dictionary;
    DictionaryFileReader* fileReader;
    set<string>* guessedWords;
    set<string>* validWords;

public:

    //
    // Creates a controller which holds a dictionary, a file reader, and sets of data for guessed words and valid words
    //
    // @precondition none
    // @postcondition dictionary will be populated with the data from the dictionary file
    //
    WordScrambleController();

    //
    // Destructs the WordScrambleController
    //
    // @precondition none
    // @postcondition all fields are deleted
    //
    virtual ~WordScrambleController();

    //
    // Reads the file from the given path to the held dictionary
    //
    // @precondition file must exist
    // @postcondition dictionary contains the data from the file
    //
    // @param filename the file name
    //
    //
    void readFileToDictionary(const string& filename);

    //
    // Says whether the guess is a good one or not
    //
    // @precondition none
    // @postcondition none
    //
    // @param word the word guessed
    //
    //
    // @return true if it was a good guess
    //
    bool guessWord(const string& word);

    //
    // Finds and stores all valid words in the field which is overwritten if it is containing any previous data
    //
    // @precondition none
    // @postcondition valid words is a new collection
    //
    // @param letters the letters the valid words must be made of
    //
    //
    void setValidWordsWith(vector<char> letters);


    //
    // Gets the set of valid words
    //
    // @precondition none
    // @postcondition none
    //
    // @return the valid words
    //
    set<string>* getValidWords() const;

    //
    // Gets the set of previously guessed words
    //
    // @precondition none
    // @postcondition none
    //
    // @return the guessed words
    //
    set<string>* getGuessedWords() const;

    //
    // Gets a vector of random letters the size of letterCount
    //
    // @precondition none
    // @postcondition none
    //
    // @param letterCount the size of the output collection
    //
    // @return the guessed words
    //
    vector<char> getRandomLetters(size_t letterCount);

    //
    // Resets the data to a state of pre-game
    //
    // @precondition none
    // @postcondition valid and guessed words are cleared
    //
    void resetGame();



};
}

#endif // WORDSCRAMBLECONTROLLER_H
