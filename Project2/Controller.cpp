/*allow different granularities of runtime. You are required to have a
version of the controller that runs the entire program, however you may wish to
implement a "single-step" controller that does one at a time with the press of the
keyboard button.*/

#include "Controller.h"

enum exceptable_Opcodes{ // Should be used for translating opcode -> InstrOp
    Rtype = 0b000000,
    ADDI = 0b001000, 
    BEQ = 0b000100,
    LW =  0b100011,
    SW = 0b101011,
    J = 0b000010
};
enum RtypeFuncFields{ // Should be used for translating funcField -> desiredALU
    ADD = 0b100000,
    AND = 0b100100,
    SUB = 0b100010,
    OR = 0b100101,
    SLT = 0b101010
};

/*Class Functions*/
void Controller::decode(string binInstruction){
    m.updateBinInstruction(binInstruction);
    string out = m.getBinInstruction();

    cout<< "Bin instr: " << out << endl;
    /*
    string opcode = binInstruction.substr(0,6);

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
    */
};