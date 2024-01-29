#include "primary_compability_solver.h"

using namespace::paull_unger;
using namespace::melee_synthesis;

bool paull_unger::primary_compability_solver::check_compatible_by_outs(unsigned long long state_a, unsigned long long state_b, comp_table& comp_table)
{
	for (unsigned long long input = 0; input < _g_table.get_height(); ++input)
	{
		state_pair states_pair({ _g_table.get_value(input, state_a), _g_table.get_value(input, state_b) });

		if (!states_pair.is_compatible_internal())
		{
			comp_table.set_value(comp_value(NONE), state_a, state_b);

			return false;
		}
	}

	return true;
}

void paull_unger::primary_compability_solver::check_compatible_by_states(unsigned long long state_a, unsigned long long state_b, comp_table& comp_table)
{
	comp_value comp_pair;
	state_pair main_pair({ table_value(state_a + 1), table_value(state_b + 1) });

	for (unsigned long long input = 0; input < _g_table.get_height(); ++input)
	{
		state_pair states_pair({ _f_table.get_value(input, state_a), _f_table.get_value(input, state_b) });

		if (states_pair.is_compatible_internal())
			continue;

		if (!(main_pair == states_pair))
		{
			comp_pair.set_type(DEPENDENT);
			comp_pair.add_dependency(states_pair);
		}
	}

	comp_table.set_value(comp_pair, state_a, state_b);
}

paull_unger::primary_compability_solver::primary_compability_solver(ms::table f_table, ms::table g_table)
{
	_f_table = f_table;
	_g_table = g_table;
}

comp_table paull_unger::primary_compability_solver::solve()
{
	comp_table comp_table(_g_table.get_width());

	for (unsigned long long state_a = 0; state_a < _g_table.get_width() - 1; ++state_a)
	{
		for (unsigned long long state_b = state_a + 1; state_b < _g_table.get_width(); ++state_b)
		{
			if (!check_compatible_by_outs(state_a, state_b, comp_table))
				continue;

			check_compatible_by_states(state_a, state_b, comp_table);
		}
	}

	return comp_table;
}
