#pragma once

#include <cmath>
#include "constants.h"
#include "diff_operators.h"

double phi(int x)
{
    return - 1.0 * Hamaker_constant / (h[x] * h[x] * h[x]);
}

double re_h(int x)
{
    return - (1.0 - L) * (d_dx(h, x) * d_dx(h, x) + h[x] * d2_dx2(h, x));
}

double gamma(int x)
{
    return sqrt(2.0 * Omega) * h[x];
}

double ksi_plus(int x)
{
    double gamma_radians = gamma(x) * M_PI / 180.0;
    return cosh(gamma_radians) + cos(gamma_radians);
}

double ksi_minus(int x)
{
    double gamma_radians = gamma(x) * M_PI / 180.0;
    return cosh(gamma_radians) - cos(gamma_radians);
}

double phi_plus(int x)
{
    double gamma_radians = gamma(x) * M_PI / 180.0;
    return sinh(gamma_radians) + sin(gamma_radians);
}

double phi_minus(int x)
{
    double gamma_radians = gamma(x) * M_PI / 180.0;
    return sinh(gamma_radians) - sin(gamma_radians);
}

double q_1(int x)
{
    double gamma_radians = gamma(x) * M_PI / 180.0;
    return 3.0 * (
        (4.0 * sinh(gamma_radians) * sin(gamma_radians) - gamma(x) * (ksi_plus(x) * phi_plus(x) - ksi_minus(x) * phi_minus(x))) / 
        (2.0 * gamma(x) * gamma(x) * ksi_plus(x) * ksi_plus(x))
    );
}

double q_2(int x)
{
    return -1.0 / 3.0 + (11.0 * phi_minus(x) - 3.0 * gamma(x) * ksi_minus(x)) / (gamma(x) * gamma(x) * gamma(x) * ksi_plus(x)); 
}