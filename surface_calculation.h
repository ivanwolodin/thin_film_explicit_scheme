#pragma once

#include "diff_operators.h"
#include "utility_functions.h"


void boundary_surface(){
    h_new[0] = h_new[Nx - 2];
    h_new[Nx - 1] = h_new[1];
}

void surface_dynamics_calculation()
{
    for (int i = 1; i < Nx - 1; i++) {
        square_bracket[i] = Ga * h[i] - Ca * d2_dx2(h, i) + 0.5 * (B * B * Omega * Omega) * re_h(i) - phi(i);
    }
    
    for (int i = 1; i < Nx - 1; i++) {
        first_term_surf[i] = ((h[i] * h[i] * h[i]) / 3.0) * d_dx(square_bracket, i);
        second_term_surf[i] = (Ma / 2.0) * h[i] * h[i] * (d_dx(theta, i) - d_dx(h, i));
        third_term_surf[i] = 0.5 * (B * B * Omega * Omega) * (q_1(i) * h[i] * h[i] * pow(d_dx(h, i), 3) + q_2(i) * d_dx(h, i) * d2_dx2(h, i));
    }

    for (int i = 1; i < Nx - 1; i++) {
        sum_term_surf[i] = first_term_surf[i] + second_term_surf[i] - third_term_surf[i];
        h_new[i] = h[i] + dt * (d_dx(sum_term_surf, i));
    }
    boundary_surface();
}

void update_h()
{
    for (int i = 0; i <= Nx - 1; i++) {
        h[i] = h_new[i];
    }
}
