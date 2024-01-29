#include "abstract_sm.h"

using namespace::polish_inverse;
using namespace::melee_synthesis;

unsigned long long polish_inverse::abstract_sm::decode(unsigned long long value)
{
	if (_from_zero)
		return value;
	else
		return value - 1;
}

polish_inverse::abstract_sm::abstract_sm()
{
	_state = 0;
	_from_zero = true;
}

abstract_sm::abstract_sm(unsigned long long init_state, table f_table, table g_table)
{
	_state = init_state;
	_f_table = f_table;
	_g_table = g_table;
	_from_zero = true;
}

polish_inverse::abstract_sm::abstract_sm(unsigned long long init_state, ms::table f_table, ms::table g_table, bool from_zero)
{
	_state = init_state;
	_f_table = f_table;
	_g_table = g_table;
	_from_zero = from_zero;
}

void polish_inverse::abstract_sm::set_state(unsigned long long state)
{
	_state = state;
}

void abstract_sm::next(unsigned long long input)
{
	auto next_state = _f_table.get_value(input, decode(_state));

	if (next_state.get_type() == TV_VALUE)
		_state = next_state.get_value();
}

unsigned long long polish_inverse::abstract_sm::get_out(unsigned long long input)
{
	return _g_table.get_value(input, decode(_state)).get_value();
}

table_value polish_inverse::abstract_sm::get_raw_out(unsigned long long input)
{
	return _g_table.get_value(input, decode(_state));
}

unsigned long long polish_inverse::abstract_sm::get_state(unsigned long long input)
{
	return _state;
}
