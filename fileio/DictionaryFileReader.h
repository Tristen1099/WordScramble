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
class DictionaryFileReader
{

private:
    string filename;
    const static int MIN_WORD_LENGTH = 3;

public:
    DictionaryFileReader(const string& filename);

    Dictionary* readFileToDictionary();

private:
    bool char_isspace(char c);

};
}

#endif // DICTIONARYFILEREADER_H
