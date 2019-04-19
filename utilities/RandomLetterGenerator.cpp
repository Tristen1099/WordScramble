#include "RandomLetterGenerator.h"


char* RandomLetterGenerator::makeRandomUniqueLetterArray(size_t charCount)
{
    vector<char> potentials = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if (charCount > potentials.size())
    {
        throw out_of_range("Cannot produce unique letter array larger than the size of the alphabet");
    }

    char* output = new char[charCount]();

    for (int i = 0; i < charCount; i++)
    {
        size_t randomIndex = rand() % potentials.size();
        output[i] = potentials[randomIndex];
        potentials.erase(potentials.begin() + randomIndex);
    }
    return output;
}
