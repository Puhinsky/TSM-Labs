#include "pic_calculator.h"

using namespace::std;

int polish_inverse::pic_calculator::get_operand(std::stack<lexem>& store, std::vector<int>& results)
{
	int operand;

	if (store.top().get_type() == 1)
	{
		operand = results[store.top().get_code()];
	}
	else
	{
		operand = store.top().get_code();
	}

	store.pop();

	return operand;
}

int polish_inverse::pic_calculator::apply_operation(lexem operation, int operant1, int operand2)
{
	switch ((char)operation.get_code())
	{
		case '+': return operant1 + operand2;
		case '-': return operant1 - operand2;
		case '*': return operant1 * operand2;
		case '/': return operant1 / operand2;
		default: return 0;
	}
}

polish_inverse::pic_calculator::pic_calculator()
{}

std::vector<int> polish_inverse::pic_calculator::run(std::vector<lexem> lexems)
{
	stack<lexem> store;
	vector<int> results;

	store.push(lexem(0, '@'));

	for (const auto& current_lexem : lexems)
	{
		if (current_lexem.get_type() == 0 || current_lexem.get_type() == 1)
		{
			store.push(current_lexem);
		}
		else
		{
			if (current_lexem.get_code() == ';')
			{
				results.push_back(store.top().get_code());
				store.pop();
			}
			else
			{
				auto operant2 = get_operand(store, results);
				auto operant1 = get_operand(store, results);
				store.push(lexem(0, apply_operation(current_lexem, operant1, operant2)));
			}
		}
	}

	return results;
}
