#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>

#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

//
// The size of the alphabet
//
static const int ALPHABET_SIZE = 26;

//
// returns string with no whitespaces
//
string removeWhitespaces(string str);

//
// plays the wow sounds
//
void playWow();



#endif // UTILS_H
