/*allow different granularities of runtime. You are required to have a
version of the controller that runs the entire program, however you may wish to
implement a "single-step" controller that does one at a time with the press of the
keyboard button.*/

#include "Controller.h"
#include "View.h"

enum exceptable_Opcodes{ // Should be used for translating opcode -> InstrOp
    Rtype = 0b000000,
    ADDI = 0b001000, 
    BEQ = 0b000100,
    LW =  0b100011,
    SW = 0b101011,
    J = 0b000010
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
    string funcField = mInstruction.substr(25,6);
    cout << "FUNCFIELD: " << funcField << endl;
    string desiredALU;
    if (InstrOp == "Rtype"){
        if(funcField == "100000"){desiredALU = "ADD";}
        else if(funcField == "100100"){desiredALU = "AND";}
        else if(funcField == "100010"){desiredALU = "SUB";}
        else if(funcField == "100101"){desiredALU = "OR";}
        else if(funcField == "101010"){desiredALU = "SLT";}
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
    string dALU = m.getDesiredALU();
    cout << "DesiredALU: " << dALU << endl;
    
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
        // address = immediate for ADDI
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
    int newValue;
    string InstrOP = m.getInstrOp();
    map<string,int> tempRegs = m.getRegisters();
    map<string,int> tempMem = m.getMemory();
    
    string rs = to_string(m.getRS());
    rs = "R" + rs;
    string rt = to_string(m.getRT());
    rt = "R" + rt;

    auto rsValue = tempRegs.find(rs);
    auto rtValue = tempRegs.find(rt);
    if(InstrOP == "Rtype"){
        string rd = to_string(m.getRD());
        rd = "R" + rd;
        if(m.getDesiredALU() == "ADD"){
            newValue = rtValue->second + rsValue->second;
        }
        else if(m.getDesiredALU() == "AND"){
            newValue = rtValue->second & rsValue->second;
        }
        else if(m.getDesiredALU() == "SUB"){
            newValue = rsValue->second - rtValue->second;
        }
        else if(m.getDesiredALU() == "OR"){
            newValue = rtValue->second | rsValue->second;
        }
        else if(m.getDesiredALU() == "SLT"){
            if(rsValue->second < rtValue->second){ newValue = 1;}
            else{ newValue = 0;}
        }
        m.updateRegisters(rd, newValue);
    }
    else if(m.getInstrOp() == "ADDI"){
        int immediate = m.getAddress();
        newValue = rsValue->second + immediate;
        cout<< "NEWVALUE: " << newValue << endl;
        m.updateRegisters(rt, newValue);
    }
    else if(m.getInstrOp() == "LW"){ // rt, immediate(rs) -> (immediate(what is stored at this memory location) + (rs)) -> rt 
        string immediateStr = to_string(m.getAddress());
        auto memValue = tempMem.find(immediateStr);
        newValue = rsValue->second + memValue->second;
        m.updateRegisters(rt, newValue);
    }
    else if(m.getInstrOp() == "SW"){ // rt, immediate(rs) -> (rtValue) ->(stored)-> (immediate location + rsValue)
        string immediateStr = to_string(m.getAddress());
        int newLocation = stoi(immediateStr,nullptr,2) + rsValue->second;
        string location = to_string(newLocation);
        m.updateMemory(location, rtValue->second);
    }
    /*
    else if(m.getInstrOp() == "BEQ"){
        // IF RS AND RT ARE EQUAL BRANCH TO LABEL
    }
    */
    Model tempModel = incrementPC(m);
    updateView(tempModel);
};

Model Controller::incrementPC(Model m)
{
    string operation = m.getInstrOp();
    int lastPCAddr = m.getPC().back();

    cout << "Initial last PC Address: " << m.getPC().back() << endl;

    if(operation == "Rtype" || operation == "LW" || operation == "SW" || operation == "ADDI")
    {
        lastPCAddr += 4;
    }
    else
    {
        int regVals = 0;
        map<string, int> regMap = m.getRegisters();
        map<string, int>::iterator it = regMap.begin();

        while(it != regMap.end())
        {
            regVals += it->second;
            ++it;
        }

        lastPCAddr += regVals;
    }

    m.updatePC(lastPCAddr);

    cout << "Last PC Address: " << m.getPC().back() << endl;

    return m;
}

void Controller::updateView(Model m)
{
    v.printLogicBlockStats(m);
    v.printBorder();
    v.printPC(m);
    v.printBorder();
    v.printRegisters(m);
    v.printBorder();
    v.printMemory(m);
}