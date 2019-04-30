#ifndef RANDOMLETTERGENERATOR_H
#define RANDOMLETTERGENERATOR_H


#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <map>
using namespace std;

namespace model
{

//
// Generates random letters in a group the given size
//
class RandomLetterGenerator
{

public:

    //
    // Makes a collection of random letters the given size
    //
    // @precondition none
    // @postcondition none
    //
    // @param size the size of the letter collection
    //
    // @return the collection of letters
    //
    static vector<char> makeRandomLetterCollection(size_t size);

private:
    static vector<char> createWeightedAlphabetVector();
    static map<char, size_t> createWeightedAlphabetMap();
    static void removeEach(char charToRemove, vector<char>* charVector);

};

}

#endif // RANDOMLETTERGENERATOR_H
