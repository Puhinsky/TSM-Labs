#include "struct_synthesis.h"

void struct_synthesis::code_states()
{
	for (auto i = 1; i <= _f_table.get_width(); i++)
	{
		_state_map.code(i, i - 1);
	}
}

struct_synthesis::struct_synthesis(input_table f_table, input_table g_table)
{
	_f_table = f_table;
	_g_table = g_table;
	code_states();
}

std::vector<dnf> struct_synthesis::synth_triggers()
{
	trigger_synthesis synthesis(_f_table, _state_map);

	return synthesis.synth();
}

std::vector<dnf> struct_synthesis::synth_outs()
{
	out_synthesis synthesis(_g_table, _state_map);

	return synthesis.synth();
}
