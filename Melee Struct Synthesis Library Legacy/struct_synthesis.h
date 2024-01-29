#pragma once
#include "table.h"
#include "state_map.h"
#include "trigger_synthesis.h"
#include "out_synthesis.h"
#include "melee_machine.h"

namespace melee_synthesis
{
	class struct_synthesis
	{
	private:
		table _f_table;
		table _g_table;
		state_map _state_map;

		void code_states();

	public:
		struct_synthesis(table f_table, table g_table);
		melee_machine synth();
	};
}