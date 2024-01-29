#pragma once
#include <map>
#include <vector>
#include "class_set.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class fsm_builder
	{
	private:
		std::map<state_class, std::vector<state_class>> _coverage;
		ms::table _g_table;
		std::map<state_class, unsigned long long> _rename_table;

		state_class get_first_class();
		std::map<state_class, unsigned long long> get_rename_table();
		state_class find_class_by_name(unsigned long long name, std::map<state_class, unsigned long long>& rename_table);

	public:
		fsm_builder(std::map<state_class, std::vector<state_class>> coverage, ms::table g_table);

		ms::table build_states_table();
		ms::table build_outs_table();
	};
}
