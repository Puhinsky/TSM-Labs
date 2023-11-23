#pragma once
#include <vector>
#include <stack>
#include "lexem.h"

namespace polish_inverse
{
	class pic_calculator
	{
	private:
		int get_operand(std::stack<lexem>& store, std::vector<int>& results);
		int apply_operation(lexem operation, int operant1, int operand2);
	public:
		pic_calculator();

		std::vector<int> run(std::vector<lexem> lexems);
	};
}