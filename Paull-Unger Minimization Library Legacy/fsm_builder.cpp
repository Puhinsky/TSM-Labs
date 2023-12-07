#include "fsm_builder.h"

using namespace::std;
using namespace::paull_unger;
using namespace::melee_synthesis;

state_class paull_unger::fsm_builder::get_first_class()
{
	for (const auto& state_class : _coverage)
	{
		for (const auto& state : state_class.first)
		{
			if (state == 1)
				return state_class.first;
		}
	}

	return state_class();
}

std::map<state_class, unsigned long long> paull_unger::fsm_builder::get_rename_table()
{
	map<state_class, unsigned long long> rename_table;
	std::map<state_class, std::vector<state_class>> _coverage_without_first = _coverage;

	auto first_class = get_first_class();
	_coverage_without_first.erase(first_class);
	rename_table.insert({ first_class, 1 });

	unsigned long long state = 2;

	for (const auto& state_class : _coverage_without_first)
	{
		rename_table.insert({ state_class.first, state });
		state++;
	}

	return rename_table;
}

state_class paull_unger::fsm_builder::find_class_by_name(unsigned long long name, std::map<state_class, unsigned long long>& rename_table)
{
	for (const auto& states_class : rename_table)
	{
		if (states_class.second == name)
			return states_class.first;
	}

	return state_class();
}

paull_unger::fsm_builder::fsm_builder(std::map<state_class, std::vector<state_class>> coverage, ms::table g_table)
{
	_coverage = coverage;
	_g_table = g_table;
	_rename_table = get_rename_table();
}

ms::table paull_unger::fsm_builder::build_states_table()
{
	table f_table;
	f_table.set_size(_coverage.size(), _g_table.get_height());

	for (unsigned long long i = 0; i < f_table.get_width(); ++i)
	{
		auto main_state_class = find_class_by_name(i + 1, _rename_table);

		for (unsigned long long input = 0; input < f_table.get_height(); ++input)
		{
			state_class states_class = _coverage[main_state_class][input];

			if (states_class.size() > 0)
			{
				unsigned long long state = _rename_table[states_class];
				f_table.set_value(input, i, table_value(state));
			}
			else
			{
				f_table.set_value(input, i, table_value());
			}
		}
	}

	return f_table;
}

ms::table paull_unger::fsm_builder::build_outs_table()
{
	table g_table;
	g_table.set_size(_coverage.size(), _g_table.get_height());

	for (unsigned long long i = 0; i < _g_table.get_width(); ++i)
	{
		auto main_state_class = find_class_by_name(i + 1, _rename_table);

		for (unsigned long long input = 0; input < _g_table.get_height(); ++input)
		{
			for (const auto& state : main_state_class)
			{
				auto out = _g_table.get_value(input, state - 1);

				if (out.get_type() == TV_VALUE)
				{
					g_table.set_value(input, i, out);

					break;
				}
			}
		}
	}

	return g_table;
}
