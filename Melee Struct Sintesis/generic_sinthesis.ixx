export module generic_sinthesis;

import <vector>;
import input_table;
import state_map;
import math_ext;
import minterms_set;

export class generic_sinthesis
{
private:
	input_table _table;
protected:
	state_map _state_map;
	std::vector<minterms_set> _sdnfs;
	unsigned long long _trigger_count;

	void on_table_value();
	void on_table_undetermined();
public:
	generic_sinthesis(input_table table, state_map state_map);
	std::vector<minterms_set> synth();
};

void generic_sinthesis::on_table_value()
{}

void generic_sinthesis::on_table_undetermined()
{}

generic_sinthesis::generic_sinthesis(input_table table, state_map state_map)
{
	_table = table;
	_state_map = state_map;
	_trigger_count = log2_int(_table.get_width());
}

std::vector<minterms_set> generic_sinthesis::synth()
{
	for (auto column = 0; column < _table.get_width(); ++column)
	{
		for (auto row = 0; row < _table.get_height(); ++row)
		{
			auto raw_state = _table.get_value(row, column);

			if (raw_state.get_type() == TV_VALUE)
			{
				on_table_value();
			}
			else
			{
				on_table_undetermined();
			}
		}
	}

	return _sdnfs;
}
