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
    this->resetButton = new Fl_Button(8, 110, 90, 30, "Reset Game");

    this->gameTitle = new Fl_Box(270,8, 50,50,"~The Word Scrambler~");
    this->wordGuessInput = new Fl_Input(230, 250, 200, 25, "Enter Guess Here:");
    this->removeLetterButton = new Fl_Button(435, 248, 30, 30, "<-");
    this->clearLettersButton = new Fl_Button(470, 248, 30, 30, "X");

    this->scoreTitle = new Fl_Box(522,170, 50,50,"~Score~");
    this->strSecondsRemaining = new string("0");
    this->currentScore = new Fl_Box(522,195, 50,50,"0");

    this->timeRemainingTitle = new Fl_Box(521,70, 50,50," ~Time~ \n ~Remaining~");
    this->currentTime = new Fl_Box(512,112, 70,50,this->strSecondsRemaining->c_str());

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(105, 70, 390, 150);

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
    this->timeRemainingTitle->labelcolor(fontColor);
    this->summaryOutputTextDisplay->color(backgroundColor);

    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);

    this->buttonLetterBoard = vector<string*>();
    this->buttonBoard = vector<Fl_Button*>();

    this->wordGuessInput->deactivate();
    this->scrambleButton->deactivate();
    this->enterButton->deactivate();
    this->removeLetterButton->deactivate();
    this->clearLettersButton->deactivate();
    this->currentTime->hide();
    this->previousLetter = nullptr;

    this->createAndDisplayLetterRadioButtons();
    this->createAndDisplayTimeRadioButtons();

    this->gameTitle->labelfont(fontStyle);
    this->scoreTitle->labelfont(fontStyle);
    this->gameTitle->labelsize(fontSize);
    this->scoreTitle->labelsize(scoreFontSize);
    this->newGameButton->box(FL_RSHADOW_BOX);
    this->resetButton->box(FL_RSHADOW_BOX);
    this->scrambleButton->box(FL_RSHADOW_BOX);
    this->enterButton->box(FL_RSHADOW_BOX);
    this->timeRadioGroup->box(FL_SHADOW_BOX);
    this->letterRadioGroup->box(FL_SHADOW_BOX);
    this->removeLetterButton->box(FL_RSHADOW_BOX);
    this->clearLettersButton->box(FL_RSHADOW_BOX);

    DictionaryFileReader* reader = new DictionaryFileReader("other/dictionary.txt");
    this->dictionary = reader->readFileToDictionary();


    end();

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

string* WordScrambleWindow::getTimeString()
{
    return this->strSecondsRemaining;
}

void WordScrambleWindow::setTimeString(string time)
{
    *this->strSecondsRemaining = time;
}

void WordScrambleWindow::decreaseSecondsRemaining()
{
    this->secondsRemaining--;
}
int WordScrambleWindow::getSecondsRemaining()
{
    return this->secondsRemaining;
}


void WordScrambleWindow::cbStartNewGame(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    Fl::remove_timeout(Timer_CB, window);

    window->begin();
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
    window->end();

    std::vector<char> validLetters;
    for (int i=0; i<window->buttonLetterBoard.size(); i++)
    {
        string *letter;
        letter = window->buttonLetterBoard[i];

        validLetters.push_back(letter->at(0));
    }

    window->allValidWords = window->dictionary->findAllWordsContaining(validLetters);

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
    window->wordGuessInput->value("");

    createButtonBoard(window);

}

void WordScrambleWindow::cdRemoveLetter(Fl_Widget* widget, void* data)
{

    WordScrambleWindow* window = (WordScrambleWindow*)data;

    if(window->previousLetter != nullptr)
    {
        window->previousLetter->show();

        window->userWordInput = window->userWordInput.substr(0, window->userWordInput.size()-1);

        window->wordGuessInput->value(window->userWordInput.c_str());

    }

    window->previousLetter = nullptr;

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


























    window->wordGuessInput->value("");
}

void WordScrambleWindow::cbLetterButtonPressed(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->addLetterToInput(widget->label());
    Fl_Button* button = (Fl_Button*)widget;
    button->hide();
    window->previousLetter = button;

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

inline void WordScrambleWindow::instantiateButtonBoardInline(size_t buttonCount)
{
    vector<char> randomLetters = RandomLetterGenerator::makeRandomLetterCollection(buttonCount);

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

    delete this->allValidWords;



}



}
