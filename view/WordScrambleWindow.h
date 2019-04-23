#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>


#include <vector>
#include <iostream>
using namespace std;

///Local import don't work after being pulled so try using ../{package_name}/{class_name}
/// - Jacob

#include "../model/RandomLetterGenerator.h"
using namespace model;

namespace view
{


class WordScrambleWindow : public Fl_Window
{


private:
    int timeRemaining;
    Fl_Button* newGameButton;
    Fl_Button* scrambleButton;
    Fl_Button* enterButton;
    Fl_Box *gameTitle;
    Fl_Input* wordGuessInput;
    Fl_Text_Buffer *summaryOutputTextBuffer;
    Fl_Text_Display *summaryOutputTextDisplay;

    vector<Fl_Button*> buttonBoard;
    vector<string*> buttonLetterBoard;

    int letterCount = 7;
    string userWordInput;
    void addLetterToInput(const char* letter);

public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();
    static void cbStartNewGame(Fl_Widget* widget, void* data);
    static void cbScrambleLetters(Fl_Widget* widget, void* data);
    static void cbEnterWord(Fl_Widget* widget, void* data);
    static void cbLetterButtonPressed(Fl_Widget* widget, void* data);
    void setSummaryText(const string& outputText);

private:

    inline void createButtonBoardInline(size_t buttonCount);



};

}

#endif // WORDSCRAMBLEWINDOW_H
