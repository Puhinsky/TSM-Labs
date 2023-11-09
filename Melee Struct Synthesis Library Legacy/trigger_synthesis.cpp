#include "trigger_synthesis.h"

using namespace::melee_synthesis;
using namespace::quine_mc_cluskey;
using namespace::logic_math;

void trigger_synthesis::init_sdnfs()
{
	for (unsigned int i = 0; i < _triggers_count; i++)
		minterms_sets.push_back(minterms_set());
}

void trigger_synthesis::on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value)
{
	auto state = _state_map.decode(raw_value);

	for (unsigned int trigger = 0; trigger < _triggers_count; trigger++)
	{
		if (get_bit(state, trigger))
			minterms_sets[trigger].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1)), LV_TRUE));
	}
}

void trigger_synthesis::on_table_undetermined(unsigned long long row, unsigned long long column)
{
	for (unsigned int trigger = 0; trigger < _triggers_count; trigger++)
	{
		minterms_sets[trigger].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1)), LV_UNDETERMINED));
	}
}
