#ifndef WORDSCRAMBLEWINDOW_H
#define WORDSCRAMBLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace view
{


class WordScrambleWindow : public Fl_Window
{
public:
    WordScrambleWindow(int width, int height, const char* title);
    virtual ~WordScrambleWindow();

protected:

private:
};

}

#endif // WORDSCRAMBLEWINDOW_H
