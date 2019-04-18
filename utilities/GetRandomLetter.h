#ifndef GETRANDOMLETTER_H
#define GETRANDOMLETTER_H

#include <vector>
using namespace std;

namespace utilities
{


class GetRandomLetter
{
public:
    GetRandomLetter();
    virtual ~GetRandomLetter();


private:
    vector<char> setFrequency;
    void populateSetFrequency();
};
}
#endif // GETRANDOMLETTER_H
