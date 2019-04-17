#include "WordScrambleWindow.h"

namespace view
{

WordScrambleWindow::WordScrambleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->timeRemaining = 0;
}

WordScrambleWindow::~WordScrambleWindow()
{
    //dtor
}

}
