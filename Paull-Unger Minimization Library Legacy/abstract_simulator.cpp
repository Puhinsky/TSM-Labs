#include "abstract_simulator.h"

using namespace::melee_synthesis;

paull_unger::abstract_simulator::abstract_simulator(pi::abstract_sm melee_machine)
{
	_melee_machine = melee_machine;
}

void paull_unger::abstract_simulator::simulate(std::vector<unsigned long long> inputs, unsigned long long begin_state)
{
	_inputs = inputs;
	_melee_machine.set_state(begin_state);

	for (auto input : _inputs)
	{
		_states.push_back(_melee_machine.get_state(input));
		_outs.push_back(_melee_machine.get_raw_out(input));
		_melee_machine.next(input);
	}
}

ms::table paull_unger::abstract_simulator::get_report()
{
	table report;

	report.set_size(3, _inputs.size());

	for (unsigned input = 0; input < _inputs.size(); input++)
	{
		report.set_value(input, 0, _inputs[input]);
		report.set_value(input, 1, _states[input]);
		report.set_value(input, 2, _outs[input]);
	}

	return report;
}


