#include "table_value.h"

using namespace::melee_synthesis;

table_value::table_value()
{
	_type = TV_UNDETERMINED;
	_value = 0;
}

table_value::table_value(unsigned long long value)
{
	_type = TV_VALUE;
	_value = value;
}

table_value::table_value(std::string value)
{
	if (value == "-")
	{
		_type = TV_UNDETERMINED;
		_value = 0;
	}
	else
	{
		_type = TV_VALUE;
		_value = stoi(value);
	}
}

unsigned long long table_value::get_value() const
{
	return _value;
}

table_value_type table_value::get_type() const
{
	return _type;
}

size_t table_value::get_hash() const
{
	if (_type == TV_UNDETERMINED)
		return 0;
	else
		return std::hash<unsigned long long>()(_value);
}

bool table_value::operator==(const table_value& other) const
{
	bool result = _type == TV_UNDETERMINED || other._type == TV_UNDETERMINED || _value == other._value;

	return result;
}

std::istream& melee_synthesis::operator>>(std::istream& is, table_value& table_value)
{
	std::string s;
	is >> s;

	if (s == "-")
	{
		table_value._type = TV_UNDETERMINED;
	}
	else
	{
		table_value._type = TV_VALUE;
		table_value._value = stoi(s);
	}

	return is;
}

size_t table_value::hash::operator()(const table_value& value) const
{
	return std::hash<unsigned long long>()(value._value)
		^ std::hash<table_value_type>()(value._type);
}
