#include "DictionaryFileReader.h"


namespace fileio
{

DictionaryFileReader::DictionaryFileReader(const string& path)
{
    this->path = path;
}

bool DictionaryFileReader::char_isspace(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

Dictionary* DictionaryFileReader::readFileToDictionary()
{
    string line;
    ifstream infile(this->path);
    vector<string> words;

    while (getline(infile, line))
    {
        string cleanLine = removeWhitespaces(line);
        if (cleanLine.size() >= MIN_WORD_LENGTH)
        {
            words.push_back(cleanLine);
        }
    }

    return new Dictionary(words);
}


}

