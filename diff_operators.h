#pragma once

#include <vector>
#include "constants.h"

// double d_dx(std::vector<double>& func, int i)   
// {
//     return (func[i + 1] - func[i - 1]) / (2.0 * dx);
// }

// double d2_dx2(std::vector<double>& func, int i)
// {
//     return (func[i + 1] - 2.0 * func[i] + func[i - 1]) / (dx * dx);
// }

inline double d_dx(const std::vector<double>& f, int i)
{
    const int N = static_cast<int>(f.size());

    // 4‑й порядок:  −f_{i+2}+8f_{i+1}−8f_{i−1}+f_{i−2}  / 12dx
    if (i >= 2 && i <= N - 3)
        return (-f[i + 2] + 8.0 * f[i + 1] - 8.0 * f[i - 1] + f[i - 2]) / (12.0 * dx);

    // 2‑й порядок (пограничный слой):  f_{i+1}−f_{i−1} / 2dx
    if (i == 1 || i == N - 2)
        return (f[i + 1] - f[i - 1]) / (2.0 * dx);

    throw std::out_of_range("d_dx: index touches periodic nodes 0 or N-1");
}

inline double d2_dx2(const std::vector<double>& f, int i)
{
    const int N = static_cast<int>(f.size());

    // 4‑й порядок:  −f_{i+2}+16f_{i+1}−30f_i+16f_{i−1}−f_{i−2}  / 12dx²
    if (i >= 2 && i <= N - 3)
        return (-f[i + 2] + 16.0 * f[i + 1] - 30.0 * f[i] +
                 16.0 * f[i - 1] -  f[i - 2]) / (12.0 * dx * dx);

    // 2‑й порядок (пограничный слой):  f_{i+1}−2f_i+f_{i−1} / dx²
    if (i == 1 || i == N - 2)
        return (f[i + 1] - 2.0 * f[i] + f[i - 1]) / (dx * dx);

    throw std::out_of_range("d2_dx2: index touches periodic nodes 0 or N-1");
}