#pragma once
#include "comp_value.h"
#include "comp_table.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class primary_compability_solver
	{
	private:
		ms::table _f_table;
		ms::table _g_table;

		bool check_compatible_by_outs(unsigned long long state_a, unsigned long long state_b, comp_table& comp_table);
		void check_compatible_by_states(unsigned long long state_a, unsigned long long state_b, comp_table& comp_table);

	public:
		primary_compability_solver(ms::table f_table, ms::table g_table);
		comp_table solve();
	};
}

