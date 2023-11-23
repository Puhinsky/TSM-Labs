#include "abstract_sm.h"

using namespace::polish_inverse;
using namespace::melee_synthesis;

polish_inverse::abstract_sm::abstract_sm()
{
	_state = 0;
}

abstract_sm::abstract_sm(unsigned long long init_state, table f_table, table g_table)
{
	_state = init_state;
	_f_table = f_table;
	_g_table = g_table;
}

void abstract_sm::next(unsigned long long input)
{
	auto next_state = _f_table.get_value(input, _state);

	if (next_state.get_type() == TV_VALUE)
		_state = next_state.get_value();
}

unsigned long long polish_inverse::abstract_sm::get_out(unsigned long long input)
{
	return _g_table.get_value(input, _state).get_value();
}
