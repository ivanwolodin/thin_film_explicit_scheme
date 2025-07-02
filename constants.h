#pragma once

#include <vector>
#include <cmath>

int Nx = 100;
double dx = 0.1;
double dt = 2.0 * pow(10, -8);//0.000001;

std::vector<double> h(Nx); 

std::vector<double> square_bracket(Nx); 

std::vector<double> first_term(Nx); 
std::vector<double> second_term(Nx); 
std::vector<double> third_term(Nx); 

std::vector<double> sum_term(Nx); 

double Hamaker_constant = 1.0 * pow(10, -5);
double Ma = 0.0 * pow(10, -5);
double Ca = 10.1;
double Ga = 9.8 * pow(10, -9);
double B = 1.0 * 2;
double Omega = 20;

// part of Re {H} 
double rad = ((sqrt(2.0 * Omega) / 2.0) * M_PI) / 180.0;
double L = (sqrt(2.0) / (2.0 * sqrt(Omega))) * (
    (sin(rad) * cos(rad) + sinh(rad) * cosh(rad)) / (cos(rad) * cos(rad) + cosh(rad) * cosh(rad) - 1.0)
);
