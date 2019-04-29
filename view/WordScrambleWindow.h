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
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


#include "../model/RandomLetterGenerator.h"
using namespace model;

namespace view
{


class WordScrambleWindow : public Fl_Window
{

public:
    int secondsRemaining;
    string* strSecondsRemaining;
    Fl_Box* currentTime;

private:
    Fl_Button* newGameButton;
    Fl_Button* scrambleButton;
    Fl_Button* enterButton;
    Fl_Box* gameTitle;
    Fl_Box* scoreTitle;
    Fl_Box* currentScore;
    Fl_Box* timeRemainingTitle;
    Fl_Input* wordGuessInput;
    Fl_Text_Buffer* summaryOutputTextBuffer;
    Fl_Text_Display* summaryOutputTextDisplay;


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

    static void createButtonBoard(WordScrambleWindow* window);
    static int getOffsetIncrement(WordScrambleWindow* window);

    inline void instantiateButtonBoardInline(size_t buttonCount);

};

}

#endif // WORDSCRAMBLEWINDOW_H
