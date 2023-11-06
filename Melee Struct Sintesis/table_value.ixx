export module table_value;

import <string>;
import <istream>;
import table_value_type;

export class table_value
{
private:
	table_value_type _type;
	unsigned long long _value;
public:
	table_value(std::string value);
	
	unsigned long long get_value();
	table_value_type get_type();

	friend std::istream& operator>>(std::istream& is, table_value& table_value);
};

table_value::table_value(std::string value)
{
	if (value == "-")
	{
		_type = UNDETERMINED;
		_value = 0;
	}
	else
	{
		_type = VALUE;
		_value = stoi(value);
	}
}

unsigned long long table_value::get_value()
{
	return _value - 1;
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
		table_value._type = UNDETERMINED;
	}
	else
	{
		table_value._type = VALUE;
		table_value._value = stoi(s);
	}

	return is;
}
