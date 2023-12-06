#include "comp_table.h"

using namespace::paull_unger;

comp_table::comp_table()
{}

comp_table::comp_table(unsigned long long states_count)
{
	_table.resize(states_count - 1);

	for (unsigned long long i = 0; i < states_count - 1; ++i)
	{
		_table[i].resize(i + 1);

		for (auto value : _table[i])
			value = true;
	}
}

void comp_table::set_value(bool value, unsigned long long state_a, unsigned long long state_b)
{
	if (state_a > state_b)
		_table[state_a - 1][state_b] = value;
	else
		_table[state_b - 1][state_a] = value;
}

bool comp_table::get_value(unsigned long long state_a, unsigned long long state_b) const
{
	if (state_a > state_b)
		return _table[state_a - 1][state_b];
	else
		return _table[state_b - 1][state_a];
}

unsigned long long paull_unger::comp_table::size() const
{
	return _table.size();
}
