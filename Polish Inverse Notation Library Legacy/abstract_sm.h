#pragma once
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

namespace polish_inverse
{
	class abstract_sm
	{
	private:
		ms::table _f_table;
		ms::table _g_table;
		unsigned long long _state;
	public:
		abstract_sm();
		abstract_sm(unsigned long long init_state, ms::table f_table, ms::table g_table);
		void next(unsigned long long input);
		unsigned long long get_out(unsigned long long input);
	};
}
