#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <iostream>
using namespace std;

#include "GetRandomLetter.h"
using namespace utilities;

namespace view
{


class WordScrambleWindow : public Fl_Window
{
public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();
    static void cbStartNewGame(Fl_Widget* widget, void* data);



private:
    int timeRemaining;
    Fl_Button* newGameButton;
    Fl_Box *gameTitle;
    vector<char> randomLetters;
};

}

#endif // WORDSCRAMBLEWINDOW_H
