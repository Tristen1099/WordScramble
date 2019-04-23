#include "WordScrambleWindow.h"

namespace view
{

WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->newGameButton = new Fl_Button(8, 70, 90, 30, "New Game");
    this->scrambleButton = new Fl_Button(475, 296, 80, 50, "Scramble");
    this->enterButton = new Fl_Button(440, 248, 60, 30, "Enter");
    this->gameTitle = new Fl_Box(270,8, 50,50,"~The Word Scrambler~");
    this->wordGuessInput = new Fl_Input(230, 250, 200, 25, "Enter Guess Here:");

    this->newGameButton->callback(cbStartNewGame, this);
    this->scrambleButton->callback(cbScrambleLetters, this);
    this->enterButton->callback(cbEnterWord, this);

    Fl_Fontsize fontSize = 40;
    Fl_Font fontStyle = 10;
    Fl_Color fontColor = fl_rgb_color(195,118,0);
    Fl_Color backgroundColor = fl_rgb_color(224,193,255);
    Fl_Color buttonColor = fl_rgb_color(204,153,0);

    this->newGameButton->color(buttonColor);
    this->scrambleButton->color(buttonColor);
    this->enterButton->color(buttonColor);

    this->gameTitle->labelsize(fontSize);
    this->gameTitle->labelfont(fontStyle);
    this->gameTitle->labelcolor(fontColor);

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(105, 70, 390, 150);
    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);
    this->summaryOutputTextDisplay->color(backgroundColor);

    this->buttonLetterBoard = vector<string*>();
    this->buttonBoard = vector<Fl_Button*>();

    this->createButtonBoardInline(this->letterCount);


    this->timeRemaining = 0;

    end();
}

void WordScrambleWindow::cbStartNewGame(Fl_Widget* widget, void* data)
{
    cout << "TEST New Game" << endl;
    WordScrambleWindow* window = (WordScrambleWindow*)data;

    window->begin();
    window->createButtonBoardInline(window->letterCount);
    window->end();


}

void WordScrambleWindow::cbScrambleLetters(Fl_Widget* widget, void* data)
{
    cout<<"TEST Scramble"<<endl;
    WordScrambleWindow* window = (WordScrambleWindow*)data;
    std::random_shuffle ( window->buttonLetterBoard.begin(), window->buttonLetterBoard.end() );
    for (size_t i = 0; i < window->buttonBoard.size(); i++)
    {
        window->buttonBoard[i]->hide();
        delete window->buttonLetterBoard[i];
        delete window->buttonBoard[i];

    }
    window->buttonBoard.clear();
    window->buttonLetterBoard.clear();
    int offset = 0;
    for (size_t i = 0; i < window->letterCount; i++)
    {
        Fl_Button* letterButton = new Fl_Button(55+offset,300, 40,40,window->buttonLetterBoard[i]->c_str());
        letterButton->callback(cbLetterButtonPressed, window);
        if(window->letterCount == 5)
        {
            offset += 85;
        }
        else if(window->letterCount == 6)
        {
            offset += 70;
        }
        else if (window->letterCount == 7)
        {
            offset += 60;
        }

        window->buttonBoard.push_back(letterButton);
        window->add(letterButton);
    }

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

inline void WordScrambleWindow::createButtonBoardInline(size_t buttonCount)
{

    //WordScrambleWindow* window = (WordScrambleWindow*)data;
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

    for (size_t i = 0; i < buttonCount; i++)
    {
        Fl_Button* letterButton = new Fl_Button(55+offset,300, 40,40,this->buttonLetterBoard[i]->c_str());
        letterButton->callback(cbLetterButtonPressed, this);
        if(this->letterCount == 5)
        {
            offset += 85;
        }
        else if(this->letterCount == 6)
        {
            offset += 70;
        }
        else if (this->letterCount == 7)
        {
            offset += 60;
        }

        this->buttonBoard.push_back(letterButton);

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
