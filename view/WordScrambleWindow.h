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
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

#include "../controller/WordScrambleController.h"
using namespace controller;

#include "../model/HighScore.h"
using namespace model;

#include "../view/WordDisplayFormatter.h"
using namespace view;

#include "../fileio/HighScoreFileReader.h"
#include "../fileio/HighScoreFileWriter.h"
using namespace fileio;

namespace view
{


class WordScrambleWindow : public Fl_Window
{

private:

    const static size_t TIME_RADIO_GROUP_SIZE = 3;
    const static size_t LETTER_RADIO_GROUP_SIZE = 3;
    const string SCORE_FILE_PATH = "other/scores.txt";

    WordScrambleController controller;


    Fl_Button* newGameButton;
    Fl_Button* resetButton;
    Fl_Button* scrambleButton;
    Fl_Button* enterButton;
    Fl_Button* removeLetterButton;
    Fl_Button* clearLettersButton;

    Fl_Box* gameTitle;
    Fl_Box* scoreTitle;
    Fl_Box* currentScore;
    Fl_Box* timeRemainingTitle;
    Fl_Box* highScoresTitle;

    Fl_Input* wordGuessInput;
    Fl_Text_Buffer* summaryOutputTextBuffer;
    Fl_Text_Display* summaryOutputTextDisplay;
    Fl_Text_Buffer* highScoreOutputTextBuffer;
    Fl_Text_Display* highScoreOutputTextDisplay;


    vector<Fl_Button*> buttonBoard;
    vector<string*> buttonLetterBoard;
    vector<Fl_Button*> previousLetterButtons;

    int letterCount;
    string userWordInput;

    int secondsRemaining;
    string* strSecondsRemaining;
    string* strCurrentScore;

    Fl_Group* timeRadioGroup;
    Fl_Round_Button* timeRadioGroupButton[TIME_RADIO_GROUP_SIZE];

    Fl_Group* letterRadioGroup;
    Fl_Round_Button* letterRadioGroupButton[LETTER_RADIO_GROUP_SIZE];

    vector<string> timeGroup = {"1 Minute", "2 Minutes", "3 Minutes"};
    vector<string> letterGroup = {"5 Letters", "6 Letters", "7 Letters"};

    vector<HighScore> highScores;


public:

    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();

    string* getTimeString();
    string* getScoreString();
    void setTimeString(const string& time);
    void setScoreString(const string& score);
    void decreaseSecondsRemaining();
    void updateCurrentTimeLabel();
    void updateCurrentScoreLabel();
    int getSecondsRemaining();
    Fl_Box* currentTime;

    static void cbStartNewGame(Fl_Widget* widget, void* data);
    static void cbResetGame(Fl_Widget* widget, void* data);
    static void cbScrambleLetters(Fl_Widget* widget, void* data);
    static void cbEnterWord(Fl_Widget* widget, void* data);
    static void cbLetterButtonPressed(Fl_Widget* widget, void* data);
    static void cdRemoveLetter(Fl_Widget* widget, void* data);
    static void cbClearLetters(Fl_Widget* widget, void* data);
    void setSummaryText(const string& outputText);
    void updateSummaryText();
    void setHighScoreText(const string& outputText);
    void endGame();
    void wow();

private:

    static void createButtonBoard(WordScrambleWindow* window);
    static int getOffsetIncrement(WordScrambleWindow* window);

    inline void instantiateButtonBoardInline(size_t buttonCount);

    void createAndDisplayTimeRadioButtons();
    void createAndDisplayLetterRadioButtons();

    void addLetterToInput(const char* letter);

    void setValuesForLetterAndTimeSpecs();
    int getScoreForWord(const string& word);

    void updateHighScoreDisplay();
    void saveHighScores();

};

}

#endif // WORDSCRAMBLEWINDOW_H
