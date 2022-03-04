#include <iostream>

int main(){
	int number, sum(0);
	std :: cout << "Enter natural number : ";
	std::cin >> number;
	__asm {
		mov ecx, sum
		cmp number, 0
		jl end_of_program

		start :	

		mov ebx, 10
		mov edx, 0
		mov eax, number
		div ebx

		imul ecx, ebx
		add ecx, edx
		mov number, eax
		cmp number, 0
		jne start


		end_of_program :
		mov sum, ecx
	}
	std::cout << "Inverted number : " << sum ;
}
