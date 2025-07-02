#pragma once

#include <cmath>
#include "diff_operators.h"
#include "utility_functions.h"


void boundary_temperature(){
    theta_new[0] = theta_new[Nx - 2];
    theta_new[Nx - 1] = theta_new[1];
}

void f_calculation()
{
    for (int i = 0; i <= Nx - 1; i++) {
        f[i] = theta[i] - h[i];
    }
    for (int i = 1; i < Nx - 1; i++) {
        df_dx[i] = d_dx(f, i);
    }
}

void aux_calculation()
{
    f_calculation();

    for (int i = 1; i < Nx - 1; i++) {
        first_term_temprt_bracket[i] = h[i] * d_dx(theta, i);
        first_term_temprt = (1.0 / Pr) * d_dx(first_term_temprt_bracket, i);

        second_term_temprt = (1.0 / (2.0 * Pr)) * pow(d_dx(h, i), 2);

        third_term_temprt = (Bi / Pr) * f[i];
        
        // first_term_surf was alread calcltd in surface_dynamics_calculation()
        fourth_term_temprt = (first_term_surf[i] + 0.5 * Ma * h[i] * h[i] * df_dx[i]) * df_dx[i];
        
        dsquare_bracket_dx[i] = d_dx(square_bracket, i);
        temp_aux_vector_1[i] = (pow(h[i], 4) / 8.0) * dsquare_bracket_dx[i];
        temp_aux_vector_2[i] = (Ma / 6.0) * pow(h[i], 3) * df_dx[i];

    }
}

void temperature_dynamics_calculation()
{
    f_calculation();

    for (int i = 1; i < Nx - 1; i++) {
        first_term_temprt = (1.0 / Pr) * d_dx(first_term_temprt_bracket, i);
        second_term_temprt = (1.0 / (2.0 * Pr)) * pow(d_dx(h, i), 2);
        third_term_temprt = (Bi / Pr) * f[i];
        fourth_term_temprt = (first_term_surf[i] + 0.5 * Ma * h[i] * h[i] * df_dx[i]) * df_dx[i];
        fifth_term_temprt = d_dx(temp_aux_vector_1, i) + d_dx(temp_aux_vector_2, i);

        theta_new[i] = theta[i] + (dt / h[i]) * (first_term_temprt - second_term_temprt - third_term_temprt + fourth_term_temprt + fifth_term_temprt);
    }
    boundary_temperature();
}

void update_theta()
{
    for (int i = 0; i <= Nx - 1; i++) {
        theta[i] = theta_new[i];
    }
}
