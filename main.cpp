#include "view/WordScrambleWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    srand(time(0));
    WordScrambleWindow mainWindow(540, 375, "A4: Word Scramble by Jacob Slattery and Tristen Rivera");
    mainWindow.resize(800, 300, 540, 375);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
