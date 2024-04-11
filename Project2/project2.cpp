#include "View.h"
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

/*
enum exceptable_Opcodes{
    Rtype = 0b000000,
    ADDI = 0b001000, 
    BEQ = 0b000100,
    LW =  0b100011,
    SW = 0b101011,
    J = 0b000010
    };

enum RtypeFuncFields{
    ADD = 0b100000,
    AND = 0b100100,
    SUB = 0b100010,
    OR = 0b100101,
    SLT = 0b101010
};
*/

int main(int argc, char* argv[])
{
    Model m;
    string binaryLine = "00000000010000110000100000100010";

    Controller c(m);

    c.decode(binaryLine);
    c.execute();

    
    
    /*
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
    */
    return 0;
}