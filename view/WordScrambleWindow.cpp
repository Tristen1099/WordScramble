#include "WordScrambleWindow.h"

namespace view
{

WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->newGameButton = new Fl_Button(1000, 700, 90, 30, "New Game");
    this->newGameButton->callback(cbStartNewGame, this);
    this->gameTitle = new Fl_Box(242,8, 50,50,"~The Word Scrambler~");
    Fl_Fontsize fontSize = 40;
    Fl_Font fontStyle = 10;
    Fl_Color fontColor = fl_rgb_color(195,118,0);
    this->gameTitle->labelsize(fontSize);
    this->gameTitle->labelfont(fontStyle);
    this->gameTitle->labelcolor(fontColor);

    Fl_Box* test = new Fl_Box(FL_RSHADOW_BOX, 200,300, 40,40,"T");

GetRandomLetter *randomLet = new GetRandomLetter();
    for(int i = 0; i < 6; i++)
    {

        cout << randomLet->getRandomLetter() << endl;
    }


    this->timeRemaining = 0;
}

void WordScrambleWindow::cbStartNewGame(Fl_Widget* widget, void* data)
{

}

WordScrambleWindow::~WordScrambleWindow()
{
    delete this->newGameButton;
    delete this->gameTitle;
}

}
