#include <iostream>

int gcd(int n, int d) {
    int one = abs(n);
    int two = abs(d);
    int result = 0;
    __asm {
        mov eax, one
        mov ebx, two

        start :
        cmp eax, 0
            jne first
            jmp end_
            first :
        cmp ebx, 0
            jne second
            jmp end_
            second :
        cmp eax, ebx
            ja third
            jmp fourth
            third :
        cdq
            div ebx
            mov eax, edx
            jmp start
            fourth :
        mov ecx, eax
            mov eax, ebx
            mov ebx, ecx
            cdq
            div ebx
            mov eax, edx
            mov ecx, eax
            mov eax, ebx
            mov ebx, ecx
            jmp start
            end_ :
        add eax, ebx
            mov result, eax
    }
    return result;
}
int main(){
   
	int num, denom;
	std::cout << "Enter numerator : ";
	std::cin >> num;
	std::cout << "Enter denominator : ";
	std::cin >> denom;
    int numerator = abs(num);
    int denominator = abs(denom);
    int reduction = gcd(numerator, denominator);
    if (denominator == 0) {
            throw std::exception("Impossible to divide by zero");
        }
    __asm {
        mov eax, numerator
        mov ebx, reduction 
        cdq
        div ebx
        mov num, eax

        mov eax, denominator
        cdq
        div ebx
        mov denom, eax
    }
    if (denominator == 1) {
        std::cout << (((num * denom) >= 0) ? " " : "-") << numerator << "\n";
    }
    else {
        std::cout << (((num * denom) > 0) ? " " : "-") << numerator << "/" << denominator << "\n";
    }
    return 0;
}
