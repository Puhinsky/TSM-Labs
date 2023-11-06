export module trigger_sinthesis;

import input_table;
import state_map;
import minterms_set;
import math_ext;

export class trigger_sinthesis 
{
private:
	input_table _f_table;
	state_map _state_map;
	unsigned long long _trigger_count;
public:
	trigger_sinthesis(input_table f_table, state_map state_map);
	std::vector<minterms_set> synt();
};

trigger_sinthesis::trigger_sinthesis(input_table f_table, state_map state_map)
{
	_f_table = f_table;
	_state_map = state_map;
	_trigger_count = log2_int(_f_table.get_width());
}

std::vector<minterms_set> trigger_sinthesis::synt()
{
	std::vector<minterms_set> sdnfs;
	auto terms_count = _f_table.get_height() + _trigger_count;

	for (auto i = 0; i < _trigger_count; ++i)
		sdnfs.push_back(minterms_set());

	for (auto column = 0; column < _f_table.get_width(); ++column)
	{
		for (auto row = 0; row < _f_table.get_height(); ++row)
		{
			auto raw_state = _f_table.get_value(row, column);

			if (raw_state.get_type() == TV_VALUE)
			{
				auto state = _state_map.decode(raw_state.get_value());

				for (auto trigger = 0; trigger < _trigger_count; ++trigger)
				{
				}
			}
		}
	}

	return std::vector<minterms_set>();
}
