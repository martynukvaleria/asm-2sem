#include <iostream>

int main(){
	int x, result1, result2, result3 ;
	std :: cout << "Enter variable x : ";
	std ::cin >> x;
	if (x == 0) {
		throw std::exception("Impossible to divide by zero");
	}

	//1. (x^5 + 2 * (x^2 – 4) + x) / x^3

	__asm {
		mov  eax, x
		imul x
		imul x
		imul x
		imul x
		add eax, x
		mov result1, eax

		mov eax, x
		imul x
		sub eax, 4
		mov ebx, 2
		imul ebx
		add result1, eax

		mov ecx, x
		imul ecx, x
		imul ecx, x

		mov eax, result1
		idiv ecx
		mov result1, eax

	}
	std :: cout << "Result of counting the first task in assembler : " << result1 << '\n';
	std::cout << "Result of counting the first task in C++ : " << 
		(x * x * x * x * x + 2 * (x * x - 4) + x) / (x * x * x) << '\n' << '\n';

	//2. (2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x)

	__asm {
		mov ebx, 2
		
		mov eax, x
		imul ebx
		sub eax, 1

		mov result2, eax

		mov eax, x
		imul ebx
		add eax, 1

		imul result2
		mov result2, eax

		mov ecx, x
		imul ecx, ebx

		mov eax, x
		add eax, 3
		imul result2
		idiv ecx
		mov result2, eax
		
	}
	std::cout << "Result of counting the second task in assembler : " << result2 << '\n';
	std::cout << "Result of counting the second task in C++ : " <<
		(2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x) << '\n' << '\n';

	//3. (4 * x – 1) * (4 * x + 1) / 4

	__asm {
		mov ebx, 4

		mov eax, x 
		imul ebx
		sub eax, 1

		mov result3, eax

		mov eax, x
		imul ebx
		add eax, 1

		imul result3
		idiv ebx
		mov result3, eax
	}
	std::cout << "Result of counting the third task in assembler : " << result3 << '\n';
	std::cout << "Result of counting the third task in C++ : " <<
		(4 * x - 1) * (4 * x + 1) / 4 << '\n';
	return 0;
}