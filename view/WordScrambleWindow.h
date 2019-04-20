#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>


#include <vector>
#include <iostream>
using namespace std;

///Local import don't work after being pulled so try using ../{package_name}/{class_name}
/// - Jacob

#include "../utilities/RandomLetterGenerator.h"
using namespace util;

namespace view
{

class WordScrambleWindow : public Fl_Window
{

private:
    int timeRemaining;
    Fl_Button* newGameButton;
    Fl_Box *gameTitle;
    vector<char> randomLetters;

public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();
    static void cbStartNewGame(Fl_Widget* widget, void* data);


};

}

#endif // WORDSCRAMBLEWINDOW_H
