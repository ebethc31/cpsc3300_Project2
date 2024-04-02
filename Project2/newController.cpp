/*allow different granularities of runtime. You are required to have a
version of the controller that runs the entire program, however you may wish to
implement a "single-step" controller that does one at a time with the press of the
keyboard button.*/

// This is where the main function will go

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <Model.h>
using namespace std;

int main(int argc, char* argv[])
{
    fstream inFile;
    string line;

    inFile.open(argv[1]);

    //Reads line by line through the input file
    while(getline(inFile, line))
    {
        cout << line << '\n';

        Instruction currInst(line);
    }

    inFile.close();

    return 0;
}
