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
	return false;
}
