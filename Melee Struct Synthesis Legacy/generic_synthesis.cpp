#include "generic_synthesis.h"


unsigned long long generic_synthesis::get_minterm_number(unsigned long long input, unsigned long long state, unsigned long long states_width)
{
	return (input << states_width) + state;
}

generic_synthesis::generic_synthesis(input_table table, state_map state_map)
{
	_table = table;
	_state_map = state_map;
	_triggers_count = log2_int(_table.get_width());
}

std::vector<dnf> generic_synthesis::synth()
{
	auto dnfs = get_dnfs();

	for (auto& dnf : dnfs)
	{
		while (dnf.try_min_to_tdnf()) {}

		dnf.min_to_mdnf();
	}

	return dnfs;
}


std::vector<dnf> generic_synthesis::get_dnfs()
{
	for (auto column = 0; column < _table.get_width(); ++column)
	{
		for (auto row = 0; row < _table.get_height(); ++row)
		{
			auto raw_state = _table.get_value(row, column);

			if (raw_state.get_type() == TV_VALUE)
			{
				on_table_value(row, column, raw_state.get_value());
			}
			else
			{
				on_table_undetermined(row, column);
			}
		}
	}

	std::vector<dnf> dnfs;
	auto terms_count = get_terms_count();

	for (auto& minterm_set : minterms_sets)
	{
		dnf dnf(minterm_set, terms_count);
		dnfs.push_back(dnf);
	}

	return dnfs;
}

unsigned long long generic_synthesis::get_terms_count()
{
	return pow2(log2(_table.get_height()) + _triggers_count);
}
