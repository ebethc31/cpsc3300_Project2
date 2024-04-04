#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

// PC Object
class PC
{
    public:
        PC() = default;
};

// Register Object
class Register
{
    public:
        string instrOp;
        char regWrite;

        Register() = default;

        Register(Instruction instr)
        {
            //come back to make sure instructions "j" and "addi" are taken care of
            instrOp = instr.getInstrOp();

            if(instrOp == "sw" || instrOp == "beq")
            {
                regWrite = '0';
            }
            else if(instrOp == "R-type" || instrOp == "lw")
            {
                regWrite = '1';
            }
        }
};

// Memory Object
class Memory
{
    public:
        string instrOp;
        char memWrite;

        Memory() = default;

        Memory(Instruction instr)
        {
            //come back to make sure instructions "j" and "addi" are taken care of
            instrOp = instr.getInstrOp();

            if(instrOp == "R-type" || instrOp == "lw" || instrOp == "beq")
            {
                memWrite = '0';
            }
            else if(instrOp == "sw")
            {
                memWrite = '1';
            }
        }
};

// Instruction Object
class Instruction {
    public:
        string ALUOp;
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