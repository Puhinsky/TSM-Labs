#pragma once
#include <vector>
#include "../Polish Inverse Notation Library Legacy/abstract_sm.h"

namespace ms = melee_synthesis;
namespace pi = polish_inverse;

namespace paull_unger
{
	class abstract_simulator
	{
	private:
		pi::abstract_sm _melee_machine;
		std::vector<unsigned long long> _inputs;
		std::vector<unsigned long long> _states;
		std::vector<ms::table_value> _outs;

	public:
		abstract_simulator(pi::abstract_sm melee_machine);

		void simulate(std::vector<unsigned long long> inputs, unsigned long long begin_state);
		ms::table get_report();
	};
}
