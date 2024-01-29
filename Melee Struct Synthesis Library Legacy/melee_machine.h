#pragma once
#include <vector>
#include <fstream>
#include "../Quine-McCluskey Optimization Library Legacy/dnf.h"
#include "state_map.h"

namespace qmcc = quine_mc_cluskey;

namespace melee_synthesis
{
	class melee_machine
	{
	private:
		std::vector<qmcc::dnf> _triggers;
		std::vector<qmcc::dnf> _outs;
		state_map _state_map;
		unsigned int _triggers_count;

		void print_dnfs_set(std::vector<qmcc::dnf> dnfs, std::string prefix, std::ostream& os) const;

	public:
		melee_machine();
		melee_machine(std::vector<qmcc::dnf> triggers, std::vector<qmcc::dnf> outs, state_map state_map, unsigned int triggers_count);

		unsigned long long get_next_state(unsigned long long input, unsigned long long state);
		unsigned long long get_out(unsigned long long input, unsigned long long state);
		void print(std::ostream& os) const;
		void save(std::string file_path) const;
	};
}
