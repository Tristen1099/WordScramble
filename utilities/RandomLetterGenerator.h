#ifndef RANDOMLETTERGENERATOR_H
#define RANDOMLETTERGENERATOR_H

#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <map>
using namespace std;

namespace util
{

class RandomLetterGenerator
{

public:
    static char* makeRandomUniqueLetterArray(size_t size);

private:
    static vector<char> createWeightedAlphabetVector();
    static map<char, size_t> createWeightedAlphabetMap();
    static void removeEach(char charToRemove, vector<char>* charVector);

};

}

#endif // RANDOMLETTERGENERATOR_H
