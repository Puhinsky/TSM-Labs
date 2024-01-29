#include "simulator.h"

using namespace::melee_synthesis;

simulator::simulator(melee_machine melee_machine, std::vector<unsigned long long> inputs, unsigned long long begin_state)
{
	_melee_machine = melee_machine;
	_inputs = inputs;
	_begin_state = begin_state;
}

table simulator::simulate()
{
	table check_word(3, _inputs.size());
	auto state = _begin_state;

	for (unsigned long long i = 0; i < _inputs.size(); ++i)
	{
		check_word.set_value(i, 0, table_value(_inputs[i]));
		check_word.set_value(i, 1, table_value(state));
		check_word.set_value(i, 2, table_value(_melee_machine.get_out(_inputs[i], state)));
		state = _melee_machine.get_next_state(_inputs[i], state);
	}

	return check_word;
}