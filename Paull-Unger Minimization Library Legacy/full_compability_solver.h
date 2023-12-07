#pragma once
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "comp_table.h"
#include <stack>

namespace ms = melee_synthesis;

namespace paull_unger
{
	class full_compability_solver
	{
	private:
		ms::table _f_table;
		comp_table _comp_table;

		bool try_get_none_compatible_pair(state_pair& pair);
		void set_none_by_dependency(const state_pair& none_comp_pair);

	public:
		full_compability_solver(ms::table f_table);
		comp_table solve(comp_table primary_comp_table);
	};
}