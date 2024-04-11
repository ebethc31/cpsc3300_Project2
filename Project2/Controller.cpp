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
    case LW:
        InstrOp = "LW";
        break;
    case SW:
        InstrOp = "SW";
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
        // rd 
        string destination = binInstruction.substr(16,5);
        int destinationValue = stoi(destination, nullptr, 2);
        m.updateRD(destinationValue);
        cout << "rd: " << m.getRD() << endl;
        // rs  
        string  rs = binInstruction.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        m.updateRS(rsValue);
        cout << "rs: " << m.getRS() << endl;
        // rt 
        string rt = binInstruction.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        m.updateRT(rtValue);
        cout << "rt: " << m.getRT() << endl;
    }
    else if(InstrOp == "LW" || InstrOp == "SW" || InstrOp == "BEQ" || InstrOp == "ADDI"){
        // rs 
        string rs = binInstruction.substr(6,5);
        int rsValue = stoi(rs, nullptr, 2);
        m.updateRS(rsValue);
        // rt 
        string rt = binInstruction.substr(11,5);
        int rtValue = stoi(rt, nullptr, 2);
        m.updateRT(rtValue);
        // address
        string address = binInstruction.substr(16,16);
        int addressValue = stoi(address, nullptr, 2);
        m.updateAddress(addressValue);
    }
    else{ // J type
        // address
        string address = binInstruction.substr(16,16);
        int addressValue = stoi(address, nullptr, 2);
        m.updateAddress(addressValue);
    }

};

void Controller::execute(){
    string InstrOP = m.getInstrOp();
    //int IOP = stoi(InstrOP, nullptr, 2);
    map<string,int> tempRegs = m.getRegisters();

    // This is meant to be for R-types
    string rd = to_string(m.getRD());
    rd = "R" + rd;
    string rs = to_string(m.getRS());
    rs = "R" + rs;
    string rt = to_string(m.getRT());
    rt = "R" + rt;

    auto rsValue = tempRegs.find(rs);
    auto rtValue = tempRegs.find(rt);

    int newValue = rtValue->second + rsValue->second;
    cout << "rs: " << rsValue->second << endl;
    cout << "rt: " << rtValue->second << endl;
    cout << "New Value: " << newValue << endl;
    /*
    switch (IOP)
    {
    case Rtype: // RegWrite = 1 
          
        break;
    case ADDI: // RegWrite = 1 
        InstrOp = "ADDI";
        break;
    case BEQ:
        InstrOp = "BEQ";
        break;
    case J:
        InstrOp = "J";
        break;
    case LW:  // RegWrite = 1 
        InstrOp = "LW";
        break;
    case SW:
        InstrOp = "SW";
        break;
    default:
        cerr << "Invalid opcode detected" << endl;
        break;
    }
    */
};