#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>

#include "constants.h"
#include "utility_functions.h"
#include "output.h"
#include "surface_calculation.h"

using std::endl;
using std::cout;

void take_step() {
    surface_dynamics_calculation();
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
    dump_initial_params();
    
    for (int stepTime = 1; stepTime < steps_number; ++stepTime) {
        take_step();

        output_fields(stepTime);
        cout << stepTime << endl;
    }

    cout << "Simulation stopped" << endl;
}
