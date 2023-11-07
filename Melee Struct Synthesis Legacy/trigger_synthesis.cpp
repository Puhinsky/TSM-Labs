#include "trigger_synthesis.h"

void trigger_synthesis::on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value)
{
	auto state = _state_map.decode(raw_value);

	for (auto trigger = 0; trigger < _triggers_count; trigger++)
	{
		if (get_bit(state, trigger))
			minterms_sets[trigger].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1), _triggers_count), LV_TRUE));
	}
}

void trigger_synthesis::on_table_undetermined(unsigned long long row, unsigned long long column)
{
	for (auto trigger = 0; trigger < _triggers_count; trigger++)
	{
		minterms_sets[trigger].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1), _triggers_count), LV_UNDETERMINED));
	}
}
