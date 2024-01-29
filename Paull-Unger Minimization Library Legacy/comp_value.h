#pragma once
#include "comp_type.h"
#include <vector>
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include <unordered_set>
#include "state_pair.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class comp_value
	{
	private:
		comp_type _type;
		std::unordered_set<state_pair, state_pair::hash> _dependencies;

	public:
		comp_value();
		comp_value(comp_type type);

		void add_dependency(state_pair dependency);
		bool is_compatible() const;
		bool is_none_compatible() const;
		void set_type(comp_type type);
		void check_for_dependency(state_pair pair);
	};
}
