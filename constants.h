#pragma once

#include <vector>
#include <cmath>

int steps_number = 100000000;

int Nx = 100;
double dx = 0.1;
double dt = 2.0 * pow(10, -8);//0.000001;

std::vector<double> h(Nx); 
std::vector<double> h_new(Nx); 

std::vector<double> square_bracket(Nx); 

std::vector<double> first_term_surf(Nx); 
std::vector<double> second_term_surf(Nx); 
std::vector<double> third_term_surf(Nx); 

std::vector<double> sum_term_surf(Nx); 

std::vector<double> theta(Nx); 
std::vector<double> theta_new(Nx);

std::vector<double> f(Nx); // theta - h
std::vector<double> df_dx(Nx); // theta - h

std::vector<double> first_term_temprt_bracket(Nx); 
std::vector<double> dsquare_bracket_dx(Nx); 

std::vector<double> temp_aux_vector_1(Nx); 
std::vector<double> temp_aux_vector_2(Nx); 

double first_term_temprt; 
double second_term_temprt; 
double third_term_temprt; 
double fourth_term_temprt; 
double fifth_term_temprt; 

double Hamaker_constant = 1.0 * pow(10, -5);
double Ca = 7.1;
double Ga = 9.8 * pow(10, -9);
double B = 1.0 * 2;
double Omega = 2;

double Ma = 1.0 * pow(10, 2);
double Pr = 7.0;
double Bi = 1.6 * pow(10, 2);

// part of Re {H} 
double rad = ((sqrt(2.0 * Omega) / 2.0) * M_PI) / 180.0;
double L = (sqrt(2.0) / (2.0 * sqrt(Omega))) * (
    (sin(rad) * cos(rad) + sinh(rad) * cosh(rad)) / (cos(rad) * cos(rad) + cosh(rad) * cosh(rad) - 1.0)
);

