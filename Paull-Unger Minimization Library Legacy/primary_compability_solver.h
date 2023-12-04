#pragma once
#include "comp_table.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class primary_compability_solver
	{
	private:
		ms::table _g_table;

	public:
		primary_compability_solver(ms::table g_table);
		comp_table solve();
	};
}

