#include "RandomLetterGenerator.h"


char* RandomLetterGenerator::makeRandomUniqueLetterArray(int charCount)
{
    const int ALPHABET_SIZE = 26;
    char* output = new char[charCount]();
    char potentials[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < charCount; i++)
    {
        int randomIndex = rand() % ALPHABET_SIZE;
        output[i] = potentials[randomIndex];
    }
    return output;
}
