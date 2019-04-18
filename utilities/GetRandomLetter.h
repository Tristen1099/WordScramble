#ifndef GETRANDOMLETTER_H
#define GETRANDOMLETTER_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

namespace utilities
{


class GetRandomLetter
{
public:
    GetRandomLetter();
    virtual ~GetRandomLetter();
    const char getRandomLetter();

private:
    vector<char> setFrequency;
    void populateSetFrequency();
};
}
#endif // GETRANDOMLETTER_H
