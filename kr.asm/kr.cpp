#include <iostream>
#include <iomanip>

int main(){
    int len = 4;
    unsigned int cut_number(0b00001111111111111001111110000000);//268410752
    unsigned int num[4];
    num[0] = 0b00010000000000010000000000000000; //268500992   
    num[1] = 0b00100000000000001000000000000000; //536903680
    num[2] = 0b01000000000000000000001000000000; //1073742336
    num[3] = 0b10000000000000000000000010000000; //2147483776

    __asm {
            xor eax, eax
            xor ecx, ecx
            xor edx, edx

        first_step :

            push ecx
            xor ecx, ecx

         second_step :

            mov eax,[num + 4*ecx]
            and eax, cut_number
            mov edx,[num + 4 * ecx + 4]
            and edx, cut_number

            cmp edx, eax
            jge third_step
            
            mov edx, [num + 4*ecx]
            mov eax, [num + 4*ecx + 4]
            mov [num + 4*ecx + 4], edx
            mov [num + 4*ecx], eax

        third_step :

            inc ecx
            
            mov ebx, len
            cmp ecx, ebx
            jge second_out
            jmp second_step

        second_out :

            pop ecx
            inc ecx
            cmp ecx, len
            jge out_
            jmp first_step

        out_ :
    }
    std::cout << "Sorted array : ";
    for (int i = 0; i < 4; i++) {
        std::cout << num[i] << ' ';
    }
}