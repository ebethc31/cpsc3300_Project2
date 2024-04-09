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












    /****************************************/
    /*
    //Find the opcode
    string binaryLine = "00000000010000110000100000100010";
    string opcode = binaryLine.substr(0,6);

    cout << "Opcode: " << opcode << endl;

    string InstrOp;

    int opcodeValue = stoi(opcode, nullptr, 2);

    switch (opcodeValue)
    {
    case Rtype:
        InstrOp = "Rtype";
        cout << InstrOp << endl;
        break;
    case ADDI:
        InstrOp = "ADDI";
        cout << InstrOp << endl;
        break;
    case BEQ:
        InstrOp = "BEQ";
        cout << InstrOp << endl;
        break;
    case J:
        InstrOp = "J";
        cout << InstrOp << endl;
        break;
    default:
        cerr << "Invalid opcode detected" << endl;
        break;
    }

    // Find funcField
    string funcField;
    string desiredALU;
    if (InstrOp == "Rtype"){
        funcField = binaryLine.substr(26,6);
        int funcFieldValue = stoi(funcField, nullptr, 2);
        switch (funcFieldValue)
        {
        case ADD:
            desiredALU = "ADD";
            break;
        case AND:
            desiredALU = "AND";
            break;
        case SUB:
            desiredALU = "SUB";
            break;
        case OR:
            desiredALU = "OR";
            break;
        case SLT:
            desiredALU = "SLT";
            break;
        default:
            break;
        }
    }
    else if (InstrOp == "LW" || InstrOp == "SW"){
        funcField = "XXXXXX";
        desiredALU = "ADD";
    }
    else if (InstrOp == "BEQ"){
        funcField = "XXXXXX";
        desiredALU = "SUB";
    }
    //ADD STUFF FOR J AND ADDI


    cout<< "function field: " << funcField << endl;
    cout<< "desired ALU: " << desiredALU << endl;

    // INSTRUCTION FORMAT 
    if(InstrOp == "Rtype"){
        /* rd 
        string destination = binaryLine.substr(16,5);
        int destinationValue = stoi(destination, nullptr, 2);
        cout << "rd: " << destinationValue << endl;
        /* rs 
        string  rs = binaryLine.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        cout << "rs: " << rsValue << endl;
        /* rt 
        string rt = binaryLine.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        cout << "rt: " << rtValue << endl;
    }
    else if(InstrOp == "LW" || InstrOp == "SW" || InstrOp == "BEQ"){
        /* rs 
        string rs = binaryLine.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        cout << "rs: " << rsValue << endl;
        /* rt 
        string rt = binaryLine.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        cout << "rt: " << rtValue << endl;
        /* address 
        string address = binaryLine.substr(16,5);
        cout << "address: " << address << endl;
    }

    /* ADD SOMETHING FOR J AND ADDI */

    /* REGISTER STUFF */
    
    
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