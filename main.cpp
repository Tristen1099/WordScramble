#include "view/WordScrambleWindow.h"
using namespace view;

#include "DictionaryFileReader.h"
using namespace fileio;

#include "../model/RandomLetterGenerator.h"
using namespace model;

#include "iostream"
using namespace std;

int main (int argc, char ** argv)
{


    srand(time(0));
    WordScrambleWindow mainWindow(570, 375, "A4: Word Scramble by Jacob Slattery and Tristen Rivera");
    mainWindow.resize(800, 300, 570, 375);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;



/*
    DictionaryFileReader reader("/home/csuser/GroupCWordScramble/other/dictionary.txt");
    Dictionary* dictionary = reader.readFileToDictionary();

    //vector<string> collection = {"jump", "jump" , "jump", "otherthingas"};
    //dictionary->setCollection(collection);

    RandomLetterGenerator randomLetterGenerator;
    vector<char> letters = randomLetterGenerator.makeRandomLetterCollection(6);

    vector<string> out = dictionary->findAllWordsContaining(letters);

    for (size_t i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }

    cout << endl;
    for (size_t i = 0; i < letters.size(); i++)
    {
        cout << letters[i];
    }
    cout << endl;



    delete dictionary;

    return 0;
    */

}
