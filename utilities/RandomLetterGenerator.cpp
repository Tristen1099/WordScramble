#include "RandomLetterGenerator.h"

char* RandomLetterGenerator::makeRandomUniqueLetterArray(size_t charCount)
{

    if (charCount > 26)
    {
        throw out_of_range("Cannot produce unique letter array larger than the size of the alphabet");
    }
    vector<char> weightedAlphabet = RandomLetterGenerator::createWeightedAlphabetVector();

    char* output = new char[charCount]();

    for (size_t i = 0; i < charCount; i++)
    {
        size_t randomIndex = rand() % weightedAlphabet.size();
        char newChar = weightedAlphabet[randomIndex];
        output[i] = newChar;
        RandomLetterGenerator::removeEach(newChar, &weightedAlphabet);


    }

    return output;
}


vector<char> RandomLetterGenerator::createWeightedAlphabetVector()
{
    vector<char> weightedAlphabet;
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    map<char, size_t> weightMap = RandomLetterGenerator::createWeightedAlphabetMap();

    for (size_t i = 0; i < alphabet.size(); i++)
    {
        char current = alphabet[i];
        for (size_t j = 0; j < weightMap[current]; j++)
        {
            weightedAlphabet.push_back(current);
        }

    }


    return weightedAlphabet;


}


map<char, size_t> RandomLetterGenerator::createWeightedAlphabetMap()
{
    map<char, size_t> weightMap;
    weightMap['e'] = 11;
    weightMap['t'] = 9;
    weightMap['o'] = 8;

    char sixWeight[] = {'a', 'i', 'n', 's'};
    for (size_t i = 0; i < 4; i++)
    {
        char current = sixWeight[i];
        weightMap[current] = 6;
    }

    weightMap['h'] = 5;
    weightMap['r'] = 5;

    char threeWeight[] = {'d', 'u', 'w', 'y'};
    for (size_t i = 0; i < 4; i++)
    {
        char current = threeWeight[i];
        weightMap[current] = 3;
    }

    char twoWeight[] = {'b', 'c', 'f', 'g', 'm', 'p', 'v'};
    for (size_t i = 0; i < 7; i++)
    {
        char current = twoWeight[i];
        weightMap[current] = 2;
    }

    char oneWeight[] = {'j', 'k', 'q', 'x', 'z'};
    for (size_t i = 0; i < 5; i++)
    {
        char current = oneWeight[i];
        weightMap[current] = 1;
    }
    return weightMap;

}


void RandomLetterGenerator::removeEach(char charToRemove, vector<char>* charVector)
{

    for (size_t j = 0; j < charVector->size();)
    {
        if ((*charVector)[j] == charToRemove)
        {
            charVector->erase(charVector->begin() + j);
        }
        else
        {
            j++;
        }

    }
}
