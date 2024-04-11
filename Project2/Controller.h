#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Model.h"
#include "View.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Controller{
    public:
        Controller() = default;
        Controller(Model m) : m(m){}
        void decode(string);
        void execute();
        //void save();

    private:
        Model m;
        //const View& v;
};


#endif