#include "View.h"
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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