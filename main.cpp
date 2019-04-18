#include "view/WordScrambleWindow.h"
using namespace view;

int main (int argc, char ** argv)
{
    WordScrambleWindow mainWindow(540, 375, "A4: Word Scramble by Jacob Slattery and Tristen Rivera");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
