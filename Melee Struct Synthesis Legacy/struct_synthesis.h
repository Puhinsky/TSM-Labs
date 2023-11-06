#pragma once
#include "input_table.h"
#include "state_map.h"
#include "trigger_synthesis.h"
#include "out_synthesis.h"

class struct_synthesis
{
private:
	input_table _f_table;
	input_table _g_table;
	state_map _state_map;

	void code_states();

public:
	struct_synthesis(input_table f_table, input_table g_table);
	std::vector<dnf> synth_triggers();
	std::vector<dnf> synth_outs();
};



