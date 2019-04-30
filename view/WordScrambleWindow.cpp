#include "WordScrambleWindow.h"

namespace view
{


void Timer_CB(void *data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->decreaseSecondsRemaining();
    window->begin();
    if(window->getSecondsRemaining() > 10)
    {
        window->currentTime->labelcolor(FL_BLACK);
        window->setTimeString(to_string(window->getSecondsRemaining()) + "\n second(s)");
        window->updateCurrentTimeLabel();
        Fl::repeat_timeout(1, Timer_CB, data);
    }
    else if(window->getSecondsRemaining() > 0)
    {
        window->currentTime->labelcolor(FL_RED);
        window->setTimeString(to_string(window->getSecondsRemaining()) + "\n second(s)");
        window->updateCurrentTimeLabel();
        Fl::repeat_timeout(1, Timer_CB, data);
    }
    else
    {
        window->currentTime->labelcolor(FL_BLACK);
        window->setTimeString("Times Up!");
        window->updateCurrentTimeLabel();
        Fl::remove_timeout(Timer_CB, data);
        window->endGame();

    }
    window->end();

}

WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->newGameButton = new Fl_Button(8, 70, 90, 30, "New Game");
    this->scrambleButton = new Fl_Button(470, 296, 80, 50, "Scramble");
    this->enterButton = new Fl_Button(505, 248, 60, 30, "Enter");
    this->resetButton = new Fl_Button(8, 110, 90, 30, "Exit Game");

    this->gameTitle = new Fl_Box(270,8, 50,50,"~The Word Scrambler~");
    this->wordGuessInput = new Fl_Input(230, 250, 200, 25, "Enter Guess Here:");
    this->removeLetterButton = new Fl_Button(435, 248, 30, 30, "<-");
    this->clearLettersButton = new Fl_Button(470, 248, 30, 30, "X");

    this->scoreTitle = new Fl_Box(522,170, 50,50,"~Score~");
    this->strCurrentScore = new string("0");
    this->currentScore = new Fl_Box(522,195, 50,50,this->strCurrentScore->c_str());

    this->timeRemainingTitle = new Fl_Box(521,70, 50,50," ~Time~ \n ~Remaining~");
    this->strSecondsRemaining = new string("0");
    this->currentTime = new Fl_Box(512,112, 70,50,this->strSecondsRemaining->c_str());

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(105, 70, 390, 150);

    this->highScoresTitle = new Fl_Box(25,300, 50,50,"~Top~ \n ~High~ \n ~Scores~");
    this->highScoreOutputTextBuffer = new Fl_Text_Buffer();
    this->highScoreOutputTextDisplay = new Fl_Text_Display(105, 285, 350, 80);

    this->newGameButton->callback(cbStartNewGame, this);
    this->scrambleButton->callback(cbScrambleLetters, this);
    this->enterButton->callback(cbEnterWord, this);
    this->resetButton->callback(cbResetGame, this);
    this->removeLetterButton->callback(cdRemoveLetter, this);
    this->clearLettersButton->callback(cbClearLetters, this);

    Fl_Fontsize fontSize = 40;
    Fl_Fontsize scoreFontSize = 20;
    Fl_Font fontStyle = 10;

    Fl_Color fontColor = fl_rgb_color(195,118,0);
    Fl_Color backgroundColor = fl_rgb_color(224,193,255);
    Fl_Color buttonColor = fl_rgb_color(204,153,0);
    this->newGameButton->color(buttonColor);
    this->resetButton->color(buttonColor);
    this->scrambleButton->color(buttonColor);
    this->removeLetterButton->color(buttonColor);
    this->clearLettersButton->color(buttonColor);
    this->enterButton->color(buttonColor);
    this->gameTitle->labelcolor(fontColor);
    this->scoreTitle->labelcolor(fontColor);
    this->highScoresTitle->labelcolor(fontColor);
    this->timeRemainingTitle->labelcolor(fontColor);
    this->summaryOutputTextDisplay->color(backgroundColor);
    this->highScoreOutputTextDisplay->color(backgroundColor);

    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);
    this->highScoreOutputTextDisplay->textfont(FL_COURIER);
    this->highScoreOutputTextDisplay->buffer(highScoreOutputTextBuffer);

    this->buttonLetterBoard = vector<string*>();
    this->buttonBoard = vector<Fl_Button*>();

    this->wordGuessInput->deactivate();
    this->scrambleButton->deactivate();
    this->enterButton->deactivate();
    this->removeLetterButton->deactivate();
    this->clearLettersButton->deactivate();
    this->currentTime->hide();

    this->createAndDisplayLetterRadioButtons();
    this->createAndDisplayTimeRadioButtons();

    this->gameTitle->labelfont(fontStyle);
    this->scoreTitle->labelfont(fontStyle);
    this->gameTitle->labelsize(fontSize);
    this->highScoresTitle->labelsize(scoreFontSize);
    this->scoreTitle->labelsize(scoreFontSize);
    this->newGameButton->box(FL_RSHADOW_BOX);
    this->resetButton->box(FL_RSHADOW_BOX);
    this->scrambleButton->box(FL_RSHADOW_BOX);
    this->enterButton->box(FL_RSHADOW_BOX);
    this->timeRadioGroup->box(FL_SHADOW_BOX);
    this->letterRadioGroup->box(FL_SHADOW_BOX);
    this->removeLetterButton->box(FL_RSHADOW_BOX);
    this->clearLettersButton->box(FL_RSHADOW_BOX);


    end();

}

void wow()
{

}

void WordScrambleWindow::cbStartNewGame(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->begin();

    Fl::remove_timeout(Timer_CB, window);

    window->wordGuessInput->value("");
    window->setValuesForLetterAndTimeSpecs();
    Fl::add_timeout(0, Timer_CB, window);
    window->scrambleButton->activate();
    window->enterButton->activate();
    window->letterRadioGroup->hide();
    window->timeRadioGroup->hide();
    window->currentTime->show();
    window->instantiateButtonBoardInline(window->letterCount);
    window->resetButton->show();
    window->removeLetterButton->activate();
    window->clearLettersButton->activate();
    window->highScoreOutputTextDisplay->hide();
    window->highScoresTitle->hide();
    window->setScoreString("0");
    window->updateCurrentScoreLabel();

    std::vector<char> validLetters;
    for (int i=0; i<window->buttonLetterBoard.size(); i++)
    {
        string *letter;
        letter = window->buttonLetterBoard[i];

        validLetters.push_back(letter->at(0));
    }
    window->controller.setValidWordsWith(validLetters);

    string summary = WordDisplayFormatter::format(window->controller.getGuessedWords(), window->controller.getValidWords());
    window->setSummaryText(summary);

    window->end();


}

void WordScrambleWindow::updateSummaryText()
{
    string summary = WordDisplayFormatter::format(this->controller.getGuessedWords(), this->controller.getValidWords());
    cout << summary << endl;
    this->setSummaryText(summary);
}

void WordScrambleWindow::createAndDisplayTimeRadioButtons()
{
    const int X_RADIO_GROUP = 7;
    const int Y_RADIO_GROUP = 106;
    const int WIDTH_RADIO_GROUP = 95;
    const int HEIGHT_RADIO_GROUP = 60;

    this->timeRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->timeRadioGroup->begin();

    for (int j = 0; j < TIME_RADIO_GROUP_SIZE; j++)
    {
        string label = this->timeGroup[j];
        this->timeRadioGroupButton[j] = new Fl_Round_Button(X_RADIO_GROUP, Y_RADIO_GROUP + 3 + j*20, 12, 12, label.c_str());
        this->timeRadioGroupButton[j]->type(FL_RADIO_BUTTON);
    }

    this->timeRadioGroup->end();

    this->timeRadioGroupButton[1]->set();
}

void WordScrambleWindow::createAndDisplayLetterRadioButtons()
{
    const int X_RADIO_GROUP = 7;
    const int Y_RADIO_GROUP = 170;
    const int WIDTH_RADIO_GROUP = 95;
    const int HEIGHT_RADIO_GROUP = 60;

    this->letterRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->letterRadioGroup->begin();


    for (int j = 0; j<3; j++)
    {
        string label = this->letterGroup[j];
        this->letterRadioGroupButton[j] = new Fl_Round_Button(X_RADIO_GROUP, Y_RADIO_GROUP + 3 + j*20, 12, 12, label.c_str());
        this->letterRadioGroupButton[j]->type(FL_RADIO_BUTTON);
    }

    this->letterRadioGroup->end();

    this->letterRadioGroupButton[1]->set();
}

void WordScrambleWindow::updateCurrentTimeLabel()
{
    this->currentTime->label(this->getTimeString()->c_str());
}

void WordScrambleWindow::updateCurrentScoreLabel()
{
    this->currentScore->label(this->getScoreString()->c_str());
}

string* WordScrambleWindow::getTimeString()
{
    return this->strSecondsRemaining;
}

string* WordScrambleWindow::getScoreString()
{
    return this->strCurrentScore;
}

void WordScrambleWindow::setTimeString(const string& time)
{
    *this->strSecondsRemaining = time;
}

void WordScrambleWindow::setScoreString(const string& score)
{
    *this->strCurrentScore = score;
}

void WordScrambleWindow::decreaseSecondsRemaining()
{
    this->secondsRemaining--;
}
int WordScrambleWindow::getSecondsRemaining()
{
    return this->secondsRemaining;
}


void WordScrambleWindow::cbResetGame(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->endGame();

}

void WordScrambleWindow::cbScrambleLetters(Fl_Widget* widget, void* data)
{

    WordScrambleWindow* window = (WordScrambleWindow*)data;

    std::random_shuffle ( window->buttonLetterBoard.begin(), window->buttonLetterBoard.end() );

    for (size_t i = 0; i < window->buttonBoard.size(); i++)
    {
        window->buttonBoard[i]->hide();
        delete window->buttonBoard[i];

    }

    window->buttonBoard.clear();
    window->previousLetterButtons.clear();
    window->wordGuessInput->value("");
    window->userWordInput = "";


    createButtonBoard(window);

}

void WordScrambleWindow::cdRemoveLetter(Fl_Widget* widget, void* data)
{

    WordScrambleWindow* window = (WordScrambleWindow*)data;

    if(window->previousLetterButtons.size() > 0)
    {
        Fl_Button* last = window->previousLetterButtons.back();
        last->show();
        window->previousLetterButtons.pop_back();

        window->userWordInput = window->userWordInput.substr(0, window->userWordInput.size()-1);

        window->wordGuessInput->value(window->userWordInput.c_str());

    }

}

void WordScrambleWindow::cbClearLetters(Fl_Widget* widget, void* data)
{

    WordScrambleWindow* window = (WordScrambleWindow*)data;

    for(size_t i = 0; i < window->buttonBoard.size(); i++)
    {
        window->buttonBoard[i]->show();
    }

    window->wordGuessInput->value("");
    window->userWordInput = "";

}

void WordScrambleWindow::createButtonBoard(WordScrambleWindow* window)
{
    int offset = 0;
    window->begin();
    for (size_t i = 0; i < window->letterCount; i++)
    {
        Fl_Button* letterButton = new Fl_Button(55+offset,300, 40,40,window->buttonLetterBoard[i]->c_str());
        letterButton->callback(cbLetterButtonPressed, window);
        offset += getOffsetIncrement(window);

        Fl_Color backgroundColor = fl_rgb_color(224,193,255);
        Fl_Color selectionColor = fl_rgb_color(134,113,195);
        letterButton->color(backgroundColor);
        letterButton->selection_color(selectionColor);
        letterButton->box(FL_RSHADOW_BOX);

        window->buttonBoard.push_back(letterButton);

    }
    window->end();
}

int WordScrambleWindow::getOffsetIncrement(WordScrambleWindow* window)
{
    int increment;
    if(window->letterCount == 5)
    {
        increment = 85;
    }
    else if(window->letterCount == 6)
    {
        increment = 70;
    }
    else if (window->letterCount == 7)
    {
        increment = 60;
    }
    return increment;
}

void WordScrambleWindow::cbEnterWord(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;

    string userGuess(window->wordGuessInput->value());

    if(userGuess.length() == 0)
    {
        return;
    }

    bool valid = window->controller.guessWord(userGuess);

    if(valid)
    {
        int score;
        stringstream stream;

        stream << window->currentScore->label();
        stream >> score;
        score += window->getScoreForWord(userGuess);

        string newScore;
        newScore = to_string(score);

        window->setScoreString(newScore);
        window->updateCurrentScoreLabel();
    }
    else
    {
        int score;
        stringstream stream;

        stream << window->currentScore->label();
        stream >> score;

        if(score >= 10)
        {
            score -= 10;
        }
        else
        {
            score = 0;
        }

        string newScore;
        newScore = to_string(score);

        window->setScoreString(newScore);
        window->updateCurrentScoreLabel();

    }


    for(size_t i = 0; i < window->buttonBoard.size(); i++)
    {
        window->buttonBoard[i]->show();
    }

    window->wordGuessInput->value("");
    window->userWordInput = "";
    window->updateSummaryText();
    if (valid)
    {
        playWow();
    }
}

int WordScrambleWindow::getScoreForWord(const string& word)
{
    int wordLength;
    wordLength = word.length();
    int score;
    score = 0;

    if(wordLength == 3)
    {
        score = 60;
    }
    else if(wordLength == 4)
    {
        score = 120;
    }
    else if(wordLength == 5)
    {
        score = 200;
    }
    else if(wordLength == 6)
    {
        score = 300;
    }
    else if(wordLength == 7)
    {
        score = 420;
    }

    return score;
}

void WordScrambleWindow::cbLetterButtonPressed(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->addLetterToInput(widget->label());
    Fl_Button* button = (Fl_Button*)widget;
    button->hide();
    window->previousLetterButtons.push_back(button);

    window = nullptr;
}

void WordScrambleWindow::addLetterToInput(const char* letter)
{

    this->userWordInput += letter;
    this->wordGuessInput->insert(letter, 1);

}

void WordScrambleWindow::setSummaryText(const string& outputText)
{
    this->summaryOutputTextBuffer->text(outputText.c_str());
}

void WordScrambleWindow::setHighScoreText(const string& outputText)
{
    this->highScoreOutputTextBuffer->text(outputText.c_str());
}

inline void WordScrambleWindow::instantiateButtonBoardInline(size_t buttonCount)
{
    vector<char> randomLetters = this->controller.getRandomLetters(buttonCount);

    int offset = 0;

    for (size_t i = 0; i < this->buttonBoard.size(); i++)
    {
        this->buttonBoard[i]->hide();
        delete this->buttonLetterBoard[i];
        delete this->buttonBoard[i];

    }

    this->buttonBoard.clear();
    this->buttonLetterBoard.clear();

    for (size_t i = 0; i < buttonCount; i++)
    {
        this->buttonLetterBoard.push_back(new string(1,randomLetters[i]));
    }

    createButtonBoard(this);
}


void WordScrambleWindow::endGame()
{
    cout << "Proof that he does have a heart" << endl;

    this->scrambleButton->deactivate();
    this->enterButton->deactivate();
    for (size_t i = 0; i < this->buttonBoard.size(); i++)
    {
        this->buttonBoard[i]->hide();

    }
    this->letterRadioGroup->show();
    this->timeRadioGroup->show();
    this->resetButton->hide();
    this->currentTime->hide();
    this->removeLetterButton->deactivate();
    this->clearLettersButton->deactivate();
    this->controller.resetGame();
    this->highScoreOutputTextDisplay->show();
    this->highScoresTitle->show();
    this->updateSummaryText();

}

void WordScrambleWindow::setValuesForLetterAndTimeSpecs()
{

    if(this->timeRadioGroupButton[0]->value() == 1)
    {
        this->secondsRemaining = 61;
    }
    else if(this->timeRadioGroupButton[1]->value() == 1)
    {
        this->secondsRemaining = 121;
    }
    else
    {
        this->secondsRemaining = 181;
    }


    if(this->letterRadioGroupButton[0]->value() == 1)
    {
        this->letterCount = 5;
    }
    else if(this->letterRadioGroupButton[1]->value() == 1)
    {
        this->letterCount = 6;
    }
    else
    {
        this->letterCount = 7;
    }

}


WordScrambleWindow::~WordScrambleWindow()
{
    delete this->newGameButton;
    delete this->resetButton;
    delete this->scrambleButton;
    delete this->enterButton;
    delete this->removeLetterButton;
    delete this->clearLettersButton;
    delete this->gameTitle;
    delete this->scoreTitle;
    delete this->currentScore;
    delete this->timeRemainingTitle;
    delete this->wordGuessInput;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;


    for (size_t i = 0; i < this->buttonBoard.size(); i++)
    {
        delete this->buttonBoard[i];
    }

    for (size_t i = 0; i < this->buttonLetterBoard.size(); i++)
    {
        delete this->buttonLetterBoard[i];
    }

    delete this->strSecondsRemaining;
    ///delete this->timeOutputLabel;
    delete this->timeRadioGroup;

    //delete this->timeRadioGroupButton;

    ///delete this->letterOutputLabel;
    delete this->letterRadioGroup;

    //delete this->letterRadioGroupButton;



}



}
