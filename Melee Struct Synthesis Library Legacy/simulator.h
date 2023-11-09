#pragma once
#include <vector>
#include "../Quine-McCluskey Optimization Library Legacy/dnf.h"
#include "state_map.h"
#include "melee_machine.h"
#include "table_value.h"
#include "table.h"

namespace ms = melee_synthesis;

namespace melee_synthesis
{
	class simulator
	{
	private:
		unsigned long long _begin_state;
		melee_machine _melee_machine;
		std::vector<unsigned long long> _inputs;

	public:
		simulator(melee_machine melee_machine, std::vector<unsigned long long> inputs, unsigned long long begin_state);

		ms::table simulate();
	};
}
