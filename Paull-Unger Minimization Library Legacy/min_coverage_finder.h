#pragma once
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "class_set.h"
#include <map>
#include <unordered_set>

namespace ms = melee_synthesis;

namespace paull_unger
{
	class min_coverage_finder
	{
	private:
		ms::table _f_table;
		class_set_ordered _classes;

		std::unordered_set<unsigned long long> find_unique_states();
		state_class find_unique_class(std::unordered_set<unsigned long long> unique_states);
		bool try_find_new_class(unsigned long long input, const state_class& current_class, const class_set& exist_classes, state_class new_class);
		bool try_expand_coverage(state_class& current_class, class_set& exist_classes);

	public:
		min_coverage_finder(ms::table f_table);

		class_set_ordered find(class_set_ordered max_classes);
	};
}
