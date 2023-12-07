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
		class_set_ordered _new_classes;
		std::map<state_class, std::vector<state_class>> _coverage;
		std::set<state_class> _exists_coverage;

		state_class get_min_class(unsigned long long input, state_class current_class);
		bool try_find_class_from_exists(const state_class& min_class, state_class& finded_class);
		bool try_find_class_from_all(const state_class& min_class, state_class& finded_class);

		std::set<unsigned long long> find_unique_states();
		state_class find_unique_class(std::set<unsigned long long> unique_states);

		void expand(state_class current_class, std::set<state_class>& feedback);
		void expand_by_input(unsigned long long input, state_class current_class, std::vector<state_class>& class_states, std::set<state_class>& feedback);

	public:
		min_coverage_finder(ms::table f_table);

		std::map<state_class, std::vector<state_class>> find(class_set_ordered max_classes);
	};
}
