#include <iostream>

int main(){
    int a, result;
    std::cout << "enter a : ";
    std::cin >> a;
    //а^12+а^8+а
    __asm {
        mov eax, a
        mov ecx, 11
        l1:
        imul a
        dec ecx
        cmp ecx, 0
        jg l1
        
        mov result, eax

        mov eax, a
        mov ecx, 7
        l2:
        imul a
        dec ecx
        cmp ecx, 0
        jg l2

        add result, eax
        mov eax, a
        add result, eax
    }
    std::cout << "C++ : " << pow(a, 12) + pow(a, 8) + a << '\n';
    std::cout << "Assembler : " << result;
}

