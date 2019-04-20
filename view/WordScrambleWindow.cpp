#include "WordScrambleWindow.h"

namespace view
{

WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->newGameButton = new Fl_Button(394, 247, 90, 30, "New Game");
    this->gameTitle = new Fl_Box(242,8, 50,50,"~The Word Scrambler~");
    this->wordGuessInput = new Fl_Input(185, 250, 200, 25, "Enter Guess Here");

    this->newGameButton->callback(cbStartNewGame, this);

    Fl_Fontsize fontSize = 40;
    Fl_Font fontStyle = 10;
    Fl_Color fontColor = fl_rgb_color(195,118,0);

    this->gameTitle->labelsize(fontSize);
    this->gameTitle->labelfont(fontStyle);
    this->gameTitle->labelcolor(fontColor);

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(80, 70, 380, 150);
    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);



    char* randomLetterArray = RandomLetterGenerator::makeRandomUniqueLetterArray(6);



    string randomLetter1 = string(1,randomLetterArray[0]);
    cout<<randomLetter1<<endl;
    string randomLetter2 = string(1,randomLetterArray[1]);
    cout<<randomLetter2<<endl;
    string randomLetter3 = string(1,randomLetterArray[2]);
    cout<<randomLetter3<<endl;
    string randomLetter4 = string(1,randomLetterArray[3]);
    cout<<randomLetter4<<endl;
    string randomLetter5 = string(1,randomLetterArray[4]);
    cout<<randomLetter5<<endl;
    string randomLetter6 = string(1,randomLetterArray[5]);
    cout<<randomLetter6<<endl;

    //There's a memory issue here for some reason cout works but setting it to the box does not work

    Fl_Box* letter1 = new Fl_Box(FL_RSHADOW_BOX, 70,300, 40,40,randomLetter1.c_str());
    Fl_Box* letter2 = new Fl_Box(FL_RSHADOW_BOX, 140,300, 40,40,randomLetter2.c_str());
    Fl_Box* letter3 = new Fl_Box(FL_RSHADOW_BOX, 210,300, 40,40,randomLetter3.c_str());
    Fl_Box* letter4 = new Fl_Box(FL_RSHADOW_BOX, 280,300, 40,40,randomLetter4.c_str());
    Fl_Box* letter5 = new Fl_Box(FL_RSHADOW_BOX, 350,300, 40,40,randomLetter5.c_str());
    Fl_Box* letter6 = new Fl_Box(FL_RSHADOW_BOX, 420,300, 40,40,randomLetter6.c_str());


    this->timeRemaining = 0;

    end();
}

void WordScrambleWindow::cbStartNewGame(Fl_Widget* widget, void* data)
{
    cout<<"TEST"<<endl;
}

void WordScrambleWindow::setSummaryText(const string& outputText)
{
    this->summaryOutputTextBuffer->text(outputText.c_str());
}

WordScrambleWindow::~WordScrambleWindow()
{
    delete this->newGameButton;
    delete this->gameTitle;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;
}

}
