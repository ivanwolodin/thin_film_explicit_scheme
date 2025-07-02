#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>

#include "constants.h"
#include "utility_functions.h"


using std::string;
using std::ofstream;
using std::endl;
using std::cout;
using std::to_string;

int steps_number = 100000000;


void output_field(int stepTime, string which_field) {
    ofstream filestr;

    string fileName = "res/" + which_field + "_" + to_string(stepTime) + ".txt";

    filestr.open(fileName);

    for (int x = 0; x <= Nx - 1; x++) {
        if (which_field == "h") {
            filestr << x << " " << h[x] << endl;
        }
    }

    filestr.close();
    if (filestr.is_open()) cout << "The file has not been closed!" << endl;
}

void boundary(){
    h[0] = h[Nx - 2];
    h[Nx - 1] = h[1];
}

void take_step() {
    for (int i = 1; i < Nx - 1; i++) {
        square_bracket[i] = Ga * h[i] - Ca * d2_dx2(h, i) + 0.5 * (B * B * Omega * Omega) * re_h(i) - phi(i);
    }
    
    for (int i = 1; i < Nx - 1; i++) {
        first_term[i] = ((h[i] * h[i] * h[i]) / 3.0) * d_dx(square_bracket, i);
        second_term[i] = -(Ma / 2.0) * h[i] * h[i] * d_dx(h, i);
        third_term[i] = 0.5 * (B * B * Omega * Omega) * (q_1(i) * h[i] * h[i] * pow(d_dx(h, i), 3) + q_2(i) * d_dx(h, i) * d2_dx2(h, i));
    }

    for (int i = 1; i < Nx - 1; i++) {
        sum_term[i] = first_term[i] + second_term[i] + third_term[i];
        h[i] = h[i] + dt * (d_dx(sum_term, i));
    }
    boundary();
}

void output_fields(int stepTime){
    if (stepTime % 1000000 == 0){
        output_field(stepTime, "h");
    }
}

void initial_distribution() {
    double length = 1.1;
    double d_x = length / (Nx - 1);
    double k = 2.0 * M_PI;
    double argm;
    for (int i = 0; i <= Nx - 1; i++) {
        argm = i * d_x;
        h[i] = 1.0 + 0.1 * cos(k * argm);
    }
    output_fields(0);
}

int main() {
    cout << "Thin film under vertical vibrations simulation" << endl;

    initial_distribution();

    for (int stepTime = 1; stepTime < steps_number; ++stepTime) {
        take_step();

        output_fields(stepTime);
        cout << stepTime << endl;
    }

    cout << "Simulation stopped" << endl;
}
