#include "full_compability_solver.h"

using namespace::std;
using namespace::paull_unger;
using namespace::melee_synthesis;

bool paull_unger::full_compability_solver::try_get_none_compatible_pair(state_pair& pair)
{
	for (unsigned long long state_a = 0; state_a < _f_table.get_width() - 1; ++state_a)
	{
		for (unsigned long long state_b = state_a + 1; state_b < _f_table.get_width(); ++state_b)
		{
			if (_comp_table.get_value(state_a, state_b).is_none_compatible())
			{
				pair = state_pair({ table_value(state_a + 1), table_value(state_b + 1) });
				_comp_table.set_value(comp_value(CHECKED), state_a, state_b);

				return true;
			}
		}
	}

	return false;
}

void paull_unger::full_compability_solver::set_none_by_dependency(const state_pair& none_comp_pair)
{
	for (unsigned long long state_a = 0; state_a < _f_table.get_width() - 1; ++state_a)
	{
		for (unsigned long long state_b = state_a + 1; state_b < _f_table.get_width(); ++state_b)
		{
			auto pair = _comp_table.get_value(state_a, state_b);
			pair.check_for_dependency(none_comp_pair);
			_comp_table.set_value(pair, state_a, state_b);
		}
	}
}

paull_unger::full_compability_solver::full_compability_solver(ms::table f_table)
{
	_f_table = f_table;
}

comp_table paull_unger::full_compability_solver::solve(comp_table primary_comp_table)
{
	_comp_table = primary_comp_table;
	state_pair none_comp_pair;

	while (try_get_none_compatible_pair(none_comp_pair))
	{
		set_none_by_dependency(none_comp_pair);
	}

	return _comp_table;
}
