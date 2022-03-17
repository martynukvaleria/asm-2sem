#include <iostream>

int main() {
	//50 = 2x + 3y
	//22 и 2 , 19 и 4 , 16 и 6 , 13 и 8
	//10 и 10 , 7 и 12 , 4 и 14 , 1 и 16
	int x = 1, y = 16;
	int solutions[16];
	__asm {
		xor ebx, ebx
		mov eax, x
		mov ecx, y
	_loop: 
		mov [solutions + ebx * 4], eax
		inc ebx
		mov [solutions + ebx * 4], ecx
		inc ebx
		add eax, 3
		sub ecx, 2
		jns _loop
	}
	for (int  i = 0; i < 16; i += 2){
		std::cout << "50 = 2 * " << solutions[i] << " + 3 * " << solutions[i + 1] << '\n';
	}
}