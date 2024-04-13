
#include "View.h"
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    Model m;
    View v;
    string binaryLine = "00000001001010100110000000100000";

    Controller c(m,v);

    c.decode(binaryLine);
    c.execute();
    
    return 0;
}
