#include "HighScoreFileWriter.h"


namespace fileio
{



HighScoreFileWriter::HighScoreFileWriter()
{
    //ctor
}

HighScoreFileWriter::~HighScoreFileWriter()
{
    //dtor
}

    void HighScoreFileWriter::writeToFile(const string filePath, const string output)
{
    if(filePath.empty())
    {
        cout << "File Path can not be empty." << endl;
        throw string("File Path can not be empty.");
    }

    ofstream out(filePath);
    out << output;
    out.close();

}

}
