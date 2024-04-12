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
    private:
        Model m;
        View v;
    public:
        Controller() = default;
        Controller(Model m, View v) : m(m), v(v){
            this->m = m;
            this->v = v;
        }
        void decode(string);
        void execute();
        void updateView();
        //void save();

    
};



#endif