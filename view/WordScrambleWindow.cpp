#include "WordScrambleWindow.h"

namespace view
{


void Timer_CB(void *data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->decreaseSecondsRemaining();
    window->begin();
    if(window->getSecondsRemaining() > 0)
    {
        window->setTimeString(to_string(window->getSecondsRemaining()));
        window->updateCurrentTimeLabel();
        Fl::repeat_timeout(1, Timer_CB, data);
    }
    else
    {
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
    this->enterButton = new Fl_Button(440, 248, 60, 30, "Enter");
    this->gameTitle = new Fl_Box(270,8, 50,50,"~The Word Scrambler~");
    this->wordGuessInput = new Fl_Input(230, 250, 200, 25, "Enter Guess Here:");
    this->scoreTitle = new Fl_Box(522,170, 50,50,"~Score~");
    this->secondsRemaining = DEFAULT_START_TIME;
    this->strSecondsRemaining = new string("0");

    this->currentScore = new Fl_Box(522,195, 50,50,"0");
    this->timeRemainingTitle = new Fl_Box(521,70, 50,50," ~Time~ \n ~Remaining~");
    this->currentTime = new Fl_Box(512,105, 70,50,this->strSecondsRemaining->c_str());

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(105, 70, 390, 150);


    this->wordGuessInput->deactivate();

    this->newGameButton->callback(cbStartNewGame, this);
    this->scrambleButton->callback(cbScrambleLetters, this);
    this->enterButton->callback(cbEnterWord, this);

    Fl_Fontsize fontSize = 40;
    Fl_Fontsize scoreFontSize = 20;
    Fl_Font fontStyle = 10;
    Fl_Color fontColor = fl_rgb_color(195,118,0);
    Fl_Color backgroundColor = fl_rgb_color(224,193,255);
    Fl_Color buttonColor = fl_rgb_color(204,153,0);

    this->newGameButton->color(buttonColor);
    this->scrambleButton->color(buttonColor);
    this->enterButton->color(buttonColor);
    this->gameTitle->labelcolor(fontColor);
    this->scoreTitle->labelcolor(fontColor);
    this->timeRemainingTitle->labelcolor(fontColor);
    this->summaryOutputTextDisplay->color(backgroundColor);

    this->gameTitle->labelsize(fontSize);
    this->scoreTitle->labelsize(scoreFontSize);

    this->gameTitle->labelfont(fontStyle);
    this->scoreTitle->labelfont(fontStyle);
    this->newGameButton->box(FL_RSHADOW_BOX);
    this->scrambleButton->box(FL_RSHADOW_BOX);
    this->enterButton->box(FL_RSHADOW_BOX);

    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);

    this->buttonLetterBoard = vector<string*>();
    this->buttonBoard = vector<Fl_Button*>();

    this->scrambleButton->deactivate();
    this->enterButton->deactivate();
    this->currentTime->hide();


    end();


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
void WordScrambleWindow::resetSecondsRemaining()
{
    this->secondsRemaining = DEFAULT_START_TIME;
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
    window->instantiateButtonBoardInline(window->letterCount);
    window->wordGuessInput->value("");
    window->end();
    window->secondsRemaining = DEFAULT_START_TIME;
    Fl::add_timeout(0, Timer_CB, window);
    window->scrambleButton->activate();
    window->enterButton->activate();
    window->currentTime->show();


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
    cout<<"TEST Enter"<<endl;
}

void WordScrambleWindow::cbLetterButtonPressed(Fl_Widget* widget, void* data)
{
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    window->addLetterToInput(widget->label());
    Fl_Button* button = (Fl_Button*)widget;
    button->hide();

    window = nullptr;
    button = nullptr;
}

void WordScrambleWindow::addLetterToInput(const char* letter)
{

    cout << letter << endl;
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
    this->scrambleButton->deactivate();
    this->enterButton->deactivate();
    for (size_t i = 0; i < this->buttonBoard.size(); i++)
    {
        this->buttonBoard[i]->hide();

    }

}


WordScrambleWindow::~WordScrambleWindow()
{
    delete this->newGameButton;
    delete this->gameTitle;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;
    delete this->scrambleButton;
    delete this->enterButton;
    delete this->scoreTitle;
    delete this->currentScore;
    delete this->strSecondsRemaining;

    for (size_t i = 0; i < this->buttonLetterBoard.size(); i++)
    {
        delete this->buttonLetterBoard[i];
    }
    for (size_t i = 0; i < this->buttonBoard.size(); i++)
    {
        delete this->buttonBoard[i];
    }
}



}
