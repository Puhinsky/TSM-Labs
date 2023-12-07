#include "max_classes_solver.h"

using namespace::paull_unger;
using namespace::std;

state_class paull_unger::max_classes_solver::get_class_by_state(unsigned long long state)
{
	state_class result;

	for (unsigned long long state_b = _comp_table.size() + 1; state_b > state; --state_b)
	{
		if (_comp_table.get_value(state - 1, state_b - 1).is_compatible())
			result.insert(state_b);
	}

	return result;
}

paull_unger::max_classes_solver::max_classes_solver()
{}

class_set_ordered paull_unger::max_classes_solver::solve(const comp_table comp_table)
{
	_comp_table = comp_table;
	class_set_ordered ordered_classes;

	class_set classes;
	classes = union_set_state(classes, _comp_table.size() + 1);

	for (unsigned long long state_a = _comp_table.size(); state_a > 0; --state_a)
	{
		auto state_class = get_class_by_state(state_a);
		auto intersect_with_set = intersect_set_class(classes, state_class);
		auto union_with_state = union_set_state(intersect_with_set, state_a);
		auto set = union_set_set(classes, union_with_state);
		auto reduced = reduce_set(set);
		classes = reduce_set(union_set_set(classes, union_set_state(intersect_set_class(classes, get_class_by_state(state_a)), state_a)));
	}

	for (const auto& state_class : classes)
	{
		ordered_classes.insert(state_class);
	}

	return ordered_classes;
}
