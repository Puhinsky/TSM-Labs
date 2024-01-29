#pragma once
#include "../Melee Struct Synthesis Library Legacy/table_value.h"

namespace ms = melee_synthesis;

namespace paull_unger
{
	class pair
	{
	private:
		ms::table_value _value_a;
		ms::table_value _value_b;

	public:
		pair();
		pair(ms::table_value value_a, ms::table_value value_b);
		ms::table_value get_a() const;
		ms::table_value get_b() const;
		bool is_compatible_by_outs() const;
		bool is_compatible(const pair& other) const;

		struct hash
		{
			size_t operator()(const pair& value) const;
		};
	};
}