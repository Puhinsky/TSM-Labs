#pragma once
#include "comp_type.h"
#include "pair.h"
#include <vector>
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class comp_pair
	{
	private:
		pair _pair;
		comp_type _type;
		std::vector<pair> _dependencies;

	public:
		comp_pair(pair pair);

		void solve(ms::table f_table, ms::table g_table);
	};
}
