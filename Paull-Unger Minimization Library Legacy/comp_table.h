#pragma once
#include <vector>
#include "comp_value.h"

namespace paull_unger
{
	class comp_table
	{
	private:
		std::vector<std::vector<comp_value>> _table;

	public:
		comp_table();
		comp_table(unsigned long long states_count);

		void set_value(comp_value value, unsigned long long state_a, unsigned long long state_b);
		comp_value get_value(unsigned long long state_a, unsigned long long state_b) const;
		unsigned long long size() const;
	};
}