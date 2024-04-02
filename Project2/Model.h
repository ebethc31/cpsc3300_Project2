#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

// PC Object

// Register Object

// Memory Object

// Instruction Object
class Instruction {
    public:
        unsigned int ALUOp;
        string InstrOp;
        string FunctionField;
        string DesiredAlUAction;
        string ALUControlInput;
    private:
        string opcode;

    // The public variables are all the things that are needed to find the ALU control input
    public:
        Instruction() = default;
        Instruction(string opcode): opcode(opcode){

        }
        
};

#endif