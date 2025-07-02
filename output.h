#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "constants.h"

using std::string;
using std::ofstream;
using std::endl;
using std::cout;
using std::to_string;


void output_field(int stepTime, string which_field) {
    ofstream filestr;

    string fileName = "res/" + which_field + "_" + to_string(stepTime) + ".txt";

    filestr.open(fileName);

    for (int x = 0; x <= Nx - 1; x++) {
        if (which_field == "h") {
            filestr << x << " " << h_new[x] << endl;
        }
        if (which_field == "theta") {
            filestr << x << " " << theta_new[x] << endl;
        }
    }

    filestr.close();
    if (filestr.is_open()) cout << "The file has not been closed!" << endl;
}


void output_fields(int stepTime){
    if (stepTime % 1000000 == 0){
        output_field(stepTime, "h");
        output_field(stepTime, "theta");
    }
}

void dump_initial_params() {
    ofstream filestr;

    string fileName = "initial_params.txt";

    filestr.open(fileName);
    
    filestr<<"Nx= "<< Nx << endl;

    filestr<<"dx= "   << dx << endl;
    filestr<<"dt= "   << dt << endl;
    filestr<<"Ca= "   << Ca << endl;
    filestr<<"Ga= "   << Ga << endl;
    filestr<<"B= "    << B << endl;
    filestr<<"Omega= "<< Omega << endl;

    filestr<<"Hamaker_constant= "<< Hamaker_constant << endl;
    filestr<<"Ma= "<< Ma << endl;
    filestr<<"Pr= "<< Pr << endl;
    filestr<<"Bi= "<< Bi << endl;

    filestr.close();
    if (filestr.is_open()) cout << "The file has not been closed!" << endl;
}
