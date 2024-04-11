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
    string mInstruction = m.getBinInstruction();

    cout<< "Bin instr: " << mInstruction << endl;
    string opcode = mInstruction.substr(0,6);

    cout << "Opcode: " << opcode << endl;
    m.updateOpcode(opcode);

    string InstrOp;

    int opcodeValue = stoi(opcode, nullptr, 2);

    // Find Instruction Opcode
    switch (opcodeValue)
    {
    case Rtype:
        InstrOp = "Rtype";
        break;
    case ADDI:
        InstrOp = "ADDI";
        break;
    case BEQ:
        InstrOp = "BEQ";
        break;
    case J:
        InstrOp = "J";
        break;
    default:
        cerr << "Invalid opcode detected" << endl;
        break;
    }
    m.updateInstrOp(InstrOp);
    string mIop = m.getInstrOp();
    cout << mIop << endl;

    // Find Function Field and Desired ALU
    string funcField;
    string desiredALU;
    if (InstrOp == "Rtype"){
        funcField = mInstruction.substr(26,6);
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
    else if (InstrOp == "LW" || InstrOp == "SW" || InstrOp == "ADDI"){
        funcField = "XXXXXX";
        desiredALU = "ADD";
    }
    else if (InstrOp == "BEQ" || InstrOp == "J"){
        funcField = "XXXXXX";
        desiredALU = "SUB";
    }

    m.updateFuncField(funcField);
    m.updateDesiredALU(desiredALU);

    // INSTRUCTION FORMAT 
    if(InstrOp == "Rtype"){
        /* rd */ 
        string destination = binInstruction.substr(16,5);
        int destinationValue = stoi(destination, nullptr, 2);
        cout << "rd: " << destinationValue << endl;
        /* rs */ 
        string  rs = binInstruction.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        cout << "rs: " << rsValue << endl;
        /* rt */ 
        string rt = binInstruction.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        cout << "rt: " << rtValue << endl;
    }
    else if(InstrOp == "LW" || InstrOp == "SW" || InstrOp == "BEQ"){
        /* rs */
        string rs = binInstruction.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        cout << "rs: " << rsValue << endl;
        /* rt */
        string rt = binInstruction.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        cout << "rt: " << rtValue << endl;
        /* address */ 
        string address = binInstruction.substr(16,5);
        cout << "address: " << address << endl;
    }

    /* ADD SOMETHING FOR J AND ADDI */
};

void Controller::updateView()
{
    v.printLogicBlockStats(m);
    v.printBorder();
    v.printPC(m);
    v.printBorder();
    v.printRegisters(m);
    v.printBorder();
    v.printMemory(m);
}
