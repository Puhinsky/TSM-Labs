#pragma once
#include "generic_synthesis.h"

class out_synthesis : public generic_synthesis
{
private:
	std::unordered_set<unsigned long long> _outs;

	void init_sdnfs()
	{
		for (auto i = 0; i < _outs.size(); i++)
			minterms_sets.push_back(minterms_set());
	}

	void define_outs()
	{
		for (auto column = 0; column < _table.get_width(); column++)
		{
			for (auto row = 0; row < _table.get_height(); row++)
			{
				auto value = _table.get_value(row, column);

				if (value.get_type() == TV_VALUE)
					_outs.insert(value.get_value());
			}
		}
	}

protected:
	virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_state)
	{
		for (auto out : _outs)
		{
			if (out == raw_state)
				minterms_sets[out - 1].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1), _triggers_count), LV_TRUE));
		}
	}

	virtual void on_table_undetermined(unsigned long long row, unsigned long long column)
	{
		for (auto out : _outs)
		{
			minterms_sets[out - 1].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1), _triggers_count), LV_UNDETERMINED));
		}
	}

public:
	out_synthesis(input_table table, state_map state_map) : generic_synthesis(table, state_map)
	{
		define_outs();
		init_sdnfs();
	}
};

