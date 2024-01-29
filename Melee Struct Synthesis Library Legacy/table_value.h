#pragma once
#include "table_value_type.h"
#include <string>
#include <istream>

namespace melee_synthesis
{
	class table_value
	{
	private:
		table_value_type _type;
		unsigned long long _value;
	public:
		table_value();
		table_value(unsigned long long value);
		table_value(std::string value);

		unsigned long long get_value() const;
		table_value_type get_type() const;
		size_t get_hash() const;

		bool operator == (const table_value& other) const;

		struct hash
		{
			size_t operator()(const table_value& value) const;
		};

		friend std::istream& operator>>(std::istream& is, table_value& table_value);
	};
}
