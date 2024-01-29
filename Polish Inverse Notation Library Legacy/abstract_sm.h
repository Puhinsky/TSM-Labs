#pragma once
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Melee Struct Synthesis Library Legacy/table_value.h"

namespace ms = melee_synthesis;

namespace polish_inverse
{
	class abstract_sm
	{
	private:
		ms::table _f_table;
		ms::table _g_table;
		unsigned long long _state;
		bool _from_zero;

		unsigned long long decode(unsigned long long value);

	public:
		abstract_sm();
		abstract_sm(unsigned long long init_state, ms::table f_table, ms::table g_table);
		abstract_sm(unsigned long long init_state, ms::table f_table, ms::table g_table, bool from_zero);
		void set_state(unsigned long long state);
		void next(unsigned long long input);
		unsigned long long get_out(unsigned long long input);
		ms::table_value get_raw_out(unsigned long long input);
		unsigned long long get_state(unsigned long long input);
	};
}
