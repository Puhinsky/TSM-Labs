#pragma once
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "comp_table.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class full_compability_solver
	{
	private:
		ms::table _f_table;
		comp_table _comp_table;

		bool check_compitability(pair main_pair);

	public:
		full_compability_solver(ms::table f_table);
		comp_table solve(comp_table primary_comp_table);
	};
}