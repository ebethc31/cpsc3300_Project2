#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Model{
    // Private Attributes
    private:
        int rd,rs,rt, address, numOfCylces, 
        numPCUpdates, numRegisterUpdates, numMemoryUpdates,
        numALUUpdates;
        std::string binInstruction;
        std::string opcode; // First 6 bits from instruction line
        std::string InstrOp; // Translated opcode to assembly instruction
        std::string funcField; // Last 6 bits from instruction line
        std::string desiredALU; // Translated funcField into assembly instruction

        // Storage parameters
        vector<int> PC;
        map<std::string, int> Registers;
        map<std::string, int> Memory; 
    // Public Functions
    public:
        Model(){
            PC.assign(1, 0x00000000);
            Registers.insert({"R0", 0});
            Registers.insert({"R1", 0}); 
            Registers.insert({"R2", 5}); 
            Registers.insert({"R3", 0}); 
            Registers.insert({"R4", 0}); 
            Registers.insert({"R5", 0}); 
            Registers.insert({"R6", 0});
            Registers.insert({"R7", 0});  
        }
        int getRD();
        int getRS();
        int getRT();
        int getAddress();
        std::string getBinInstruction();
        std::string getOpcode();
        std::string getInstrOp();
        std::string getFuncField();
        std::string getDesiredALU();
        vector<int> getPC();
        map<std::string, int> getRegisters();
        map<std::string, int> getMemory(); 
        void updateRD(int);
        void updateRS(int);
        void updateRT(int);
        void updateAddress(int);
        void updateBinInstruction(string);
        void updateOpcode(string);
        void updateInstrOp(string);
        void updateFuncField(string);
        void updateDesiredALU(string);
        void updatePC(int);
        void updateRegisters(string, int);
        void updateMemory(string, int);
};


/*
// Instruction Class
class Instruction {
    public:
        string fullInstr;
        string ALUOp;
        string DesiredAlUAction;
        string ALUControlInput;
        string opcode;
        string functField;
        enum class InstrOp{loadWord, storeWord, branchEqual, Rtype};
        enum class InstrOperation{LW, SW, BEQ, ADD, SUB, AND, OR, SLT, ADDI, J};

        // ADD ALU COUNTER


    // The public variables are all the things that are needed to find the ALU control input
    public:
        Instruction() = default;
        Instruction(string instruct){
            fullInstr = instruct;
        };
        
        string getOpcode();
        string getFunctField();
        InstrOp getInstrOp();
        InstrOperation getInstrOperation();
};
// PC Class
class PC
{
    public:
        PC() = default;
};

// Register Class
class Register
{
    private:
        string regs[2][8] = {
            {"R0","R1","R2","R3","R4","R5","R6","R7"},
            {"0","0","0","0","0","0","0","0"}
        };
    public:
        string instrOp;
        char regWrite;

        Register() = default;

        Register(Instruction instr)
        {
            Instruction::InstrOp instrOpEnum = instr.getInstrOp();
            
            //come back to make sure instructions "j" and "addi" are taken care of
            switch (instrOpEnum){
            case Instruction::InstrOp::storeWord:
                regWrite = '0';
                break;
            case Instruction::InstrOp::Rtype:
                regWrite = '1';
                break;
            case Instruction::InstrOp::loadWord:
                regWrite = '1';
                break;
            case Instruction::InstrOp::branchEqual:
                regWrite = '0';
                break;
            default:
                break;
            };
        }
};

// Memory Class
class Memory
{
    public:
        string instrOp;
        char memWrite;

        Memory() = default;

        Memory(Instruction instr)
        {
            Instruction::InstrOp instrOpEnum = instr.getInstrOp();

            //come back to make sure instructions "j" and "addi" are taken care of
            switch (instrOpEnum){
            case Instruction::InstrOp::storeWord:
                memWrite = '1';
                break;
            case Instruction::InstrOp::Rtype:
                memWrite = '0';
                break;
            case Instruction::InstrOp::loadWord:
                memWrite = '0';
                break;
            case Instruction::InstrOp::branchEqual:
                memWrite = '0';
                break;
            default:
                break;
            };
        };
};

*/

#endif