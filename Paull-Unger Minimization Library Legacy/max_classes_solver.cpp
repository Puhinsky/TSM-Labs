#include "max_classes_solver.h"

using namespace::paull_unger;
using namespace::std;

state_class paull_unger::max_classes_solver::get_class_by_state(unsigned long long state)
{
	state_class result;

	for (unsigned long long state_b = state; state_b < _comp_table.size(); ++state_b)
	{
		if (!_comp_table.get_value(state, state_b))
			continue;

		result.insert(state);
	}

	return result;
}

paull_unger::max_classes_solver::max_classes_solver()
{}

class_set paull_unger::max_classes_solver::solve(const comp_table comp_table)
{
	_comp_table = comp_table;

	class_set classes;
	classes = union_set_state(classes, _comp_table.size());
	unsigned long long state_a = _comp_table.size() - 1;

	do
	{
		classes = union_set_set(classes, union_set_state(intersect_set_class(classes, get_class_by_state(state_a)), state_a));
		--state_a;

	} while (state_a != 0);

	return classes;
}
