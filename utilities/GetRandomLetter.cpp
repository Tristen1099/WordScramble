#include "GetRandomLetter.h"

namespace utilities
{

GetRandomLetter::GetRandomLetter()
{
          this->populateSetFrequency();
}

GetRandomLetter::~GetRandomLetter()
{
    //dtor
}


void GetRandomLetter::populateSetFrequency()
{


    for(int i = 0; i <11; i++)
    {
        this->setFrequency.push_back('e');
    }
    for(int i = 0; i <9; i++)
    {
        this->setFrequency.push_back('t');
    }
    for(int i = 0; i <8; i++)
    {
        this->setFrequency.push_back('o');
    }
    for(int i = 0; i <6; i++)
    {
        this->setFrequency.push_back('a');
        this->setFrequency.push_back('i');
        this->setFrequency.push_back('n');
        this->setFrequency.push_back('s');
    }
    for(int i = 0; i <5; i++)
    {
        this->setFrequency.push_back('h');
        this->setFrequency.push_back('r');
    }
    for(int i = 0; i <4; i++)
    {
        this->setFrequency.push_back('l');
    }
    for(int i = 0; i <3; i++)
    {
        this->setFrequency.push_back('d');
        this->setFrequency.push_back('u');
        this->setFrequency.push_back('w');
        this->setFrequency.push_back('y');
    }
    for(int i = 0; i <2; i++)
    {
        this->setFrequency.push_back('b');
        this->setFrequency.push_back('c');
        this->setFrequency.push_back('f');
        this->setFrequency.push_back('g');
        this->setFrequency.push_back('m');
        this->setFrequency.push_back('p');
        this->setFrequency.push_back('v');
    }
    this->setFrequency.push_back('j');
    this->setFrequency.push_back('k');
    this->setFrequency.push_back('q');
    this->setFrequency.push_back('x');
    this->setFrequency.push_back('z');

}

}
