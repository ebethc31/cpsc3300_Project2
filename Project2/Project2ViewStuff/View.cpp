#include <map>
#include "View.h"
using namespace std;

void View::printBorder()
{
    cout << "\n---------------\n\n";
}

/*at least one "text" view that will display a "scoreboard" that shows the
contents of PC, registers, and memory; also, of logic block statistics - they should use the
observer pattern to implement this. Note: The view is expected to update every cycle.
For the text view, that means it should print the scoreboard on every cycle.*/
void View::printLogicBlockStats(Model m)
{
    int numCycles = m.getNumCycles();
    int numRegUpdates = m.getNumRegisterUpdates();
    int numPCUpdates = m.getNumPCUpdates();
    int numMemUpdates = m.getNumMemoryUpdates();
    int numALUArithOps = m.getNumALUArithOps();

    cout << "Logic Block Statistics:\n\n";
    cout << "Number of Cycles: " << numCycles << endl;
    cout << "Number of PC Updates: " << numPCUpdates << endl;
    cout << "Number of Register Updates: " << numRegUpdates << endl;
    cout << "Number of Memory Updates: " << numMemUpdates << endl;
    cout << "Number of ALU Arithmetic Operations: " << numALUArithOps << endl;
}

// Show the status of the PC
void View::printPC(Model m)
{

    cout << "Last PC address check: " << m.getPC().back() << endl;

    cout << "PC:\n\n";

    vector<int> PCvec = m.getPC();

    for(auto it : PCvec)
    {
        cout << it << endl;
    }
}

// Show the status of the registers
void View::printRegisters(Model m)
{
    cout << "Registers:\n\n";

    map<string, int> regMap = m.getRegisters();
    map<string, int>::iterator it = regMap.begin();

    while(it != regMap.end())
    {
        cout << it->first << ": " << it->second << endl;
        ++it;
    }
}

// Show the status of the memory
void View::printMemory(Model m)
{
    cout << "Memory:\n\n";

    map<string, int> memMap = m.getMemory();
    map<string, int>::iterator it = memMap.begin();

    while(it != memMap.end())
    {
        cout << it->first << "\t" << it->second << endl;
        ++it;
    }
}