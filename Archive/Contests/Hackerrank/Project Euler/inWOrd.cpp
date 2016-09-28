#include <iostream>

using namespace std;

string getWord(istream& in) 
{
    int c;

    string word;

    // TODO: remove whitespace from begining of stream ?

    while( !in.eof() ) 
    {

        c = in.get();

        if( c == ' ' || c == '\t' || c == '\n' ) break;

        word += c;
    }

    return word;
}

int main()
{
    string word;

    do {

        word = getWord(cin);

        cout << "[" << word << "]";

    } while( word != "#");

    return 0;
}