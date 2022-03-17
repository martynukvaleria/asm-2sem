#include <iostream>

int main(){
	int fibonacci_sequence[47];
	int counter;
	__asm {

			xor ecx, ecx
			xor eax, eax
			mov ebx, 1
			mov [fibonacci_sequence + ecx * 4], eax
			inc ecx
			mov [fibonacci_sequence + ecx * 4], ebx

		_loop:
			mov edx, ebx
			add ebx, eax
			jo _loop_end
			mov eax, edx
			inc ecx
			mov [fibonacci_sequence + ecx * 4], ebx
			jmp _loop
		_loop_end:
			mov counter, ecx
	}
	for (int i = 0; i <= counter; i++){
		std::cout << fibonacci_sequence[i] << ", ";
	}
}
