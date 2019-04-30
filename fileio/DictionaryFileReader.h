#ifndef DICTIONARYFILEREADER_H
#define DICTIONARYFILEREADER_H

#include "../model/Dictionary.h"
using namespace model;

#include "../utilities/Utils.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

namespace fileio
{

//
// A file reader designed to make Dictionary objects from the specified CSV file
//
class DictionaryFileReader
{

private:
    string path;
    const static int MIN_WORD_LENGTH = 3;

public:

    //
    // Creates a DictionaryFileReader that will read from the given path
    //
    // @precondition path must be a valid path to a valid CSV file
    // @postcondition none
    //
    // @param path the file path
    //
    DictionaryFileReader(const string& path);

    //
    // Creates a Dictionary based on the data found in the file
    //
    // @precondition none
    // @postcondition new Dictionary is created with the read data
    //
    // @return the Dictionary
    //
    Dictionary* readFileToDictionary();

private:
    bool char_isspace(char c);

};
}

#endif // DICTIONARYFILEREADER_H
