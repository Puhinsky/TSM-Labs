#include "melee_machine.h"

using namespace::melee_synthesis;
using namespace::quine_mc_cluskey;
using namespace::logic_math;

void melee_machine::print_dnfs_set(std::vector<dnf> dnfs, std::string prefix, std::ostream& os) const
{
	for (auto i = 0; i < dnfs.size(); ++i)
	{
		os << prefix << i << '\n';
		dnfs[i].print(os);
	}

	os << '\n';
}

melee_machine::melee_machine()
{
	_triggers_count = 0;
}

melee_machine::melee_machine(std::vector<dnf> triggers, std::vector<dnf> outs, state_map state_map, unsigned int triggers_count)
{
	_triggers = triggers;
	_outs = outs;
	_state_map = state_map;
	_triggers_count = triggers_count;
}

unsigned long long melee_machine::get_next_state(unsigned long long input, unsigned long long state)
{
	unsigned long long value = concat_values(input - 1, _state_map.decode(state), _triggers_count);
	unsigned long long result = 0;

	for (auto i = 0; i < _triggers.size(); ++i)
	{
		result += (unsigned long long)_triggers[i].calculate_function(value) << i;
	}

	return _state_map.code(result);
}

unsigned long long melee_machine::get_out(unsigned long long input, unsigned long long state)
{
	unsigned long long value = concat_values(input - 1, _state_map.decode(state), _triggers_count);
	unsigned long long result = 0;

	for (auto i = 0; i < _outs.size(); ++i)
	{
		result += (unsigned long long)_outs[i].calculate_function(value) << i;
	}

	return (unsigned long long)log2_int(result) + 1;
}

void melee_machine::print(std::ostream& os) const
{
	print_dnfs_set(_triggers, "Q", os);
	print_dnfs_set(_outs, "y", os);
}

void melee_machine::save(std::string file_path) const
{
	std::ofstream os(file_path);
	print(os);
	os.close();
}
