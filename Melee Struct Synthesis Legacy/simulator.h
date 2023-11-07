#pragma once
#include <vector>
#include "../Quine-McCluskey Optimizator Legacy/dnf.h"
#include "state_map.h"
#include "melee_machine.h"
#include "table_value.h"

class simulator
{
private:
	melee_machine _melee_machine;
	std::vector<unsigned long long> _inputs;
	unsigned long long _begin_state;

	std::vector<unsigned long long> _states;
	std::vector<unsigned long long> _outs;

public:
	simulator(melee_machine melee_machine, std::vector<unsigned long long> inputs, unsigned long long begin_state)
	{
		_melee_machine = melee_machine;
		_inputs = inputs;
		_begin_state = begin_state;
	}

	void simulate()
	{
		auto state = _begin_state;

		for (auto input : _inputs)
		{
			_outs.push_back(_melee_machine.get_out(input, state));
			_states.push_back(state);
			state = _melee_machine.get_next_state(input, state);
		}

		_states.push_back(state);
	}

	std::vector<unsigned long long> get_states()
	{
		return _states;
	}

	std::vector<unsigned long long> get_outs()
	{
		return _outs;
	}
};

