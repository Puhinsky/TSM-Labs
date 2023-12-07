#include "comp_value.h"

using namespace::paull_unger;

comp_value::comp_value()
{
	_type = FULL;
}

comp_value::comp_value(comp_type type)
{
	_type = type;
}

void paull_unger::comp_value::add_dependency(state_pair dependency)
{
	_dependencies.insert(dependency);
}

bool paull_unger::comp_value::is_compatible() const
{
	return _type != NONE && _type != CHECKED;
}

bool paull_unger::comp_value::is_none_compatible() const
{
	return _type == NONE;
}

void paull_unger::comp_value::set_type(comp_type type)
{
	_type = type;
}

void paull_unger::comp_value::check_for_dependency(state_pair pair)
{
	if (_dependencies.find(pair) != _dependencies.end())
		_type = NONE;
}
