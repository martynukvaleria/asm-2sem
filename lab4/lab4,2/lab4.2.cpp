#include <iostream>
#include <iomanip>
#include <bitset>

extern "C" double second(int);

double task2(int precesion);

int main()
{
    int precesion;
    std::cout << "Enter precison: ";
    std::cin >> precesion;    
   
    std::cout << std::endl << std::fixed << std::setprecision(10) <<
        "Task2: " << task2(precesion) <<'/n';
}

double task2(int precesion) {
    double answer;
    answer = second(precesion);
    return answer;
}
