#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Round_Button.H>


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

private:
    static const int DEFAULT_START_TIME = 21;

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

    int letterCount = 5;
    string userWordInput;
    void addLetterToInput(const char* letter);

    int secondsRemaining;
    string* strSecondsRemaining;
    Fl_Box* currentTime;

    Fl_Output* timeOutputLabel;
    Fl_Group* timeRadioGroup;
    Fl_Round_Button* timeRadioGroupButton[3];

    Fl_Output* letterOutputLabel;
    Fl_Group* letterRadioGroup;
    Fl_Round_Button* letterRadioGroupButton[3];

    vector<string> timeGroup = {"1 Minute", "2 Minutes", "3 Minutes"};
    vector<string> letterGroup = {"5 Letters", "6 Letters", "7 Letters"};


public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();

    string* getTimeString();
    void setTimeString(string time);
    void decreaseSecondsRemaining();
    void resetSecondsRemaining();
    void updateCurrentTimeLabel();
    int getSecondsRemaining();

    static void cbStartNewGame(Fl_Widget* widget, void* data);
    static void cbScrambleLetters(Fl_Widget* widget, void* data);
    static void cbEnterWord(Fl_Widget* widget, void* data);
    static void cbLetterButtonPressed(Fl_Widget* widget, void* data);
    void setSummaryText(const string& outputText);
    void endGame();

private:

    static void createButtonBoard(WordScrambleWindow* window);
    static int getOffsetIncrement(WordScrambleWindow* window);

    inline void instantiateButtonBoardInline(size_t buttonCount);

    void createAndDisplayTimeRadioButtons();
    void createAndDisplayLetterRadioButtons();

};

}

#endif // WORDSCRAMBLEWINDOW_H
