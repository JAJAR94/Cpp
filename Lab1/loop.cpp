//// lab1_3.cpp
#include "random.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
// template<typename T_>
// inline constexpr
//     T_ pi_v{3.141592653589793238462643383279502884L};
// inline constexpr double pi = pi_v<double>;

int main()
{
float pi = 3.141592653589793238462643383279502884;
constexpr double rnd_min = 0.0, rnd_max = 100.0;
Rand_double rnd{rnd_min, rnd_max};
std::random_device rd;
rnd.seed(rd());
std::cout << std::fixed << std::setprecision(3);
double x1 = rnd();
double y1 = rnd();
std::cout << "Point #1: (" << x1 << ", " << y1 << ")\n";
double x2 = rnd();
double y2 = rnd();
std::cout << "Point #2: (" << x2 << ", " << y2 << ")";
std::cout << std::endl;

return 0;
}