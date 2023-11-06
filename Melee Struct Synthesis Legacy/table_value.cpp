#include "table_value.h"

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

unsigned long long table_value::get_value()
{
	return _value;
}

table_value_type table_value::get_type()
{
	return _type;
}

std::istream& operator>>(std::istream& is, table_value& table_value)
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
