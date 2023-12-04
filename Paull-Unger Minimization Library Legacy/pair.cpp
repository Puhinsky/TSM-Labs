#include "pair.h"

using namespace::paull_unger;
using namespace::melee_synthesis;

pair::pair(table_value value_a,table_value value_b)
{
	_value_a = value_a;
	_value_b = value_b;
}

table_value pair::get_a() const
{
	return _value_a;
}

table_value pair::get_b() const
{
	return _value_b;
}

bool pair::is_compatible(const pair& other) const
{
	if (_value_a == other._value_a && _value_b == other._value_b)
		return true;

	if (_value_a == other._value_b && _value_b == other._value_a)
		return true;

	return false;
}

bool pair::is_compatible_by_outs() const
{
	if (_value_a.get_type() == TV_UNDETERMINED || _value_b.get_type() == TV_UNDETERMINED)
		return true;

	return _value_a.get_value() == _value_b.get_value();
}

bool pair::is_full_determined() const
{
	return _value_a.get_type() == TV_VALUE && _value_b.get_type() == TV_VALUE;
}

bool pair::is_single() const
{
	return _value_a.get_value() == _value_b.get_value();
}
