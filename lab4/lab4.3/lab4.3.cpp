#include <iostream>
#include <iomanip>
int main()
{
	double k1 = 1;
	double precision = 0.00001;
	/*std::cout << "Enter precision : ";
	std::cin >> precision;*/
	double current = 0, sum = 0, count = 0, odds = 0;
	double one = 1, neg_ = -1, zero = 0;
	int one_ = 1, k2 = 1;

	__asm
	{
	start_sum:
			finit
			fld one
			mov ecx, 0
			add ecx, k2
			add ecx, 1

		start_ :

			fmul neg_
			loop start_
			fstp current
			fld current
			fdiv k1
			fstp current
			fld sum
			fadd current
			fstp sum

			fldln2
			fsub sum
			fabs
			fstp odds

			fld odds
			fcom precision
			xor eax, eax
			fstsw ax
			sahf
			jc check_

			fld k1
			fadd one
			fstp k1
			xor ebx, ebx
			mov ebx, one_
			add k2, ebx
			jmp start_sum

		check_ :

			fld k1
			fstp count
	}

	std::cout << "Number of iterations required to find entered number of characters after comma : " ;
	std::cout << count << '\n';
	std::cout << "Value obtained by this formula : ";
	std::cout << std::setprecision(7) << sum << '\n';
}