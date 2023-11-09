#include "out_synthesis.h"

using namespace::melee_synthesis;
using namespace::quine_mc_cluskey;

void out_synthesis::define_outs()
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

void out_synthesis::init_sdnfs()
{
	for (auto i = 0; i < _outs.size(); i++)
		minterms_sets.push_back(minterms_set());
}

void out_synthesis::on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value)
{
	minterms_sets[raw_value - 1].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1)), LV_TRUE));
}

void out_synthesis::on_table_undetermined(unsigned long long row, unsigned long long column)
{
	for (auto out : _outs)
	{
		minterms_sets[out - 1].insert(minterm(get_minterm_number(row, _state_map.decode(column + 1)), LV_UNDETERMINED));
	}
}