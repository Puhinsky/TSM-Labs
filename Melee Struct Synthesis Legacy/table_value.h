#pragma once
#include "table_value_type.h"
#include <string>
#include <istream>

class table_value
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

