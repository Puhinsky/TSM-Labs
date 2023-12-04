#include "comp_table.h"

using namespace::paull_unger;

comp_table::comp_table()
{}

comp_table::comp_table(unsigned long long states_count)
{
	_table.resize(states_count);

	for (unsigned long long i = 0; i < states_count; ++i)
	{
		_table[i].resize(i + 1);

		for (auto value : _table[i])
			value = true;
	}
}

void comp_table::set_value(bool value, unsigned long long state_a, unsigned long long state_b)
{
	if (state_a > state_b)
		_table[state_a][state_b] = value;
	else
		_table[state_b][state_a] = value;
}

bool comp_table::get_value(unsigned long long state_a, unsigned long long state_b)
{
	if (state_a > state_b)
		return _table[state_a][state_b];
	else
		return _table[state_b][state_a];
}
