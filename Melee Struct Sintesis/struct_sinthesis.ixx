export module struct_sinthesis;

import input_table;
import state_map;

export class struct_sinthesis
{
private:
	input_table _f_table;
	input_table _g_table;
	state_map _state_map;

	void code_states();

public:
	struct_sinthesis(input_table f_table, input_table g_table);
	void synt_triggers();
	void synt_outs();
};

void struct_sinthesis::code_states()
{
	for (auto i = 1; i <= _f_table.get_width(); i++)
	{
		_state_map.code(i);
	}
}

struct_sinthesis::struct_sinthesis(input_table f_table, input_table g_table)
{
	_f_table = f_table;
	_g_table = g_table;
	code_states();
}

void struct_sinthesis::synt_triggers()
{}

void struct_sinthesis::synt_outs()
{}
