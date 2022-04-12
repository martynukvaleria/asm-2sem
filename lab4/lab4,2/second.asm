.model flat, C
.const
twelve real4 12.0;
.code
second PROC, precesion: dword

			mov ecx, precesion;
			fldz
			fld1
			fld1
			fld1
		
		_start :
		
			fmul st(0), st(0)
			fmul st(0), st(1)
			fld1
			fdiv st(0), st(1)
			faddp st(4), st(0)
			
			faddp st(0),st(0)
			fchs
			
			fxch st(1)
			fld1
			faddp st(1), st(0)
			fxch st(1)
			
			fldz
			fadd st(0), st(2)
		
		_loop:
		
			faddp st(0), st(0)
			faddp st(0), st(0)
			faddp st(0), st(0)
			fmul twelve
			fsqrt
			ret 
second endp
end