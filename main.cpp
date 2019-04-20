#include "view/WordScrambleWindow.h"
using namespace view;

#include "DictionaryFileReader.h"
using namespace fileio;

#include "../utilities/RandomLetterGenerator.h"
using namespace util;

#include "iostream"
using namespace std;

int main (int argc, char ** argv)
{

    srand(time(0));
    WordScrambleWindow mainWindow(540, 375, "A4: Word Scramble by Jacob Slattery and Tristen Rivera");
    mainWindow.resize(800, 300, 540, 375);
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;



    /*
    DictionaryFileReader reader("/home/csuser/GroupCWordScramble/other/dictionary.txt");
    Dictionary* dictionary = reader.readFileToDictionary();

    //vector<string> collection = {"jump", "jump" , "jump", "otherthingas"};
    //dictionary->setCollection(collection);


    vector<char> letters = RandomLetterGenerator::makeRandomUniqueLetterArray(15);

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
