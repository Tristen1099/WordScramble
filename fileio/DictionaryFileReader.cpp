#include "DictionaryFileReader.h"


namespace fileio
{

DictionaryFileReader::DictionaryFileReader(const string& filename)
{
    this->filename = filename;
}

bool DictionaryFileReader::char_isspace(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}



Dictionary* DictionaryFileReader::readFileToDictionary()
{
    string line;
    ifstream infile(this->filename);
    vector<string> words;


    while (getline(infile, line))
    {
        words.push_back(removeWhitespaces(line));

    }

    return new Dictionary(words);
}


}

