.model flat, C 
.const
	two real8 2.0;
	two1 dword 2;
.code
	fifth PROC, power: dword

		xor edx, edx
		mov ecx, 0
		xor ebx, ebx
		mov eax, power
		fld1

	start_:

		xor edx, edx
		div two1
		cmp edx, 0
		je _even

		fld two
		mov ebx, ecx
		cmp ecx, 0
		je _afterloop

	_strt:
	
		fmul st(0), st(0)
		loop _strt

	_afterloop:

		fmul st(0), st(1)
		mov ecx, ebx

		xor edx, edx
		mul two1
		jmp start_

	_even:
		
		inc ecx
		cmp eax, 1
		je _pow
		jg start_

	_zero:

		fld1
		fmul
		jmp _out

	_pow:
		fld two

	_strtloop:
		fmul st(0), st(0)
		loop _strtloop
		fmul
	_out:
		ret
	fifth ENDP
end