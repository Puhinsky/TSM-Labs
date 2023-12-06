#pragma once
#include <vector>
#include "comp_pair.h"

namespace paull_unger
{
	class comp_table
	{
	private:
		std::vector<std::vector<bool>> _table;

	public:
		comp_table();
		comp_table(unsigned long long states_count);

		void set_value(bool value, unsigned long long stateA, unsigned long long stateB);
		bool get_value(unsigned long long stateA, unsigned long long stateB) const;
		unsigned long long size() const;
	};
}