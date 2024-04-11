#ifndef VIEW_H_
#define VIEW_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Controller.h"
using namespace std;

class View
{
    public:
        View() = default;
        View(Model);
        void showInstruction();
        void showInstruction();
        void printPC(Model);
        void printRegisters(Model);
        void printMemory(Model);
        void printLogicBlockStats(Model);
        void printBorder();
};


#endif
