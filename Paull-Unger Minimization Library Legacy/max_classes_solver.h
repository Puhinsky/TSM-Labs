#pragma once
#include "class_set.h"
#include "comp_table.h"
#include <algorithm>

namespace paull_unger
{
	class max_classes_solver
	{
	private:
		comp_table _comp_table;

		state_class get_class_by_state(unsigned long long state);

	public:
		max_classes_solver();
		class_set solve(comp_table comp_table);
	};
}
