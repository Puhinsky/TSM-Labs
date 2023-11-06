#include "struct_synthesis.h"

void struct_synthesis::code_states()
{
	for (auto i = 1; i <= _f_table.get_width(); i++)
	{
		_state_map.define(i, i - 1);
	}
}

struct_synthesis::struct_synthesis(input_table f_table, input_table g_table)
{
	_f_table = f_table;
	_g_table = g_table;
	code_states();
}

melee_machine struct_synthesis::synth()
{
	trigger_synthesis t_synthesis(_f_table, _state_map);
	out_synthesis o_synthesis(_g_table, _state_map);

	return melee_machine(t_synthesis.synth(), o_synthesis.synth(), _state_map, log2_int(_f_table.get_width()));
}
