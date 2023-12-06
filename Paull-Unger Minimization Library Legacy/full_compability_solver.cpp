#include "full_compability_solver.h"

using namespace::std;
using namespace::paull_unger;

bool full_compability_solver::check_compitability(pair main_pair, pair input_pair)
{
	if (input_pair.get_a() == input_pair.get_b())
		return true;

	if (!_comp_table.get_value(input_pair.get_a().get_value() - 1, input_pair.get_b().get_value() - 1))
		return false;

	for (unsigned long long input = 0; input < _f_table.get_height(); ++input)
	{
		pair states_pair(_f_table.get_value(input, input_pair.get_a().get_value() - 1), _f_table.get_value(input, input_pair.get_b().get_value() - 1));

		if (states_pair.is_compatible(input_pair))
			continue;

		if (states_pair.is_compatible(main_pair))
			continue;

		if (check_compitability(main_pair, states_pair))
			continue;
		else
			return false;
	}

	return true;
}

full_compability_solver::full_compability_solver(ms::table f_table)
{
	_f_table = f_table;
}

comp_table paull_unger::full_compability_solver::solve(comp_table primary_comp_table)
{
	_comp_table = primary_comp_table;

	for (unsigned long long state_a = 1; state_a < _f_table.get_width(); ++state_a)
	{
		for (unsigned long long state_b = state_a + 1; state_b < _f_table.get_width() + 1; ++state_b)
		{
			pair main_pair(state_a, state_b);
			_comp_table.set_value(check_compitability(main_pair, main_pair), state_a - 1, state_b - 1);
		}
	}

	return _comp_table;
}
