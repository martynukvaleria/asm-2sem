#include <iostream>
#include <iomanip>

extern "C" double fifth(int);

double task5(int pow);

int main()
{
    int pow;
    std::cout << std::endl << "Enter the power: ";
    std::cin >> pow;
    std::cout << '\n' << std::fixed << std::setprecision(10) <<
        "Task4: " << task5(pow) << '\n';
}