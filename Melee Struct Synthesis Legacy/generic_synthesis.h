#pragma once
#include "input_table.h"
#include "state_map.h"
#include "../Quine-McCluskey Optimizator Legacy/minterm_set.h"
#include "../Quine-McCluskey Optimizator Legacy/dnf.h"

class generic_synthesis
{
private:
	std::vector<dnf> get_dnfs();
	unsigned long long get_terms_count();

protected:
	input_table _table;
	state_map _state_map;
	std::vector<minterms_set> minterms_sets;
	unsigned long long _triggers_count;

	virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value) = 0;
	virtual void on_table_undetermined(unsigned long long row, unsigned long long column) = 0;

	unsigned long long get_minterm_number(unsigned long long input, unsigned long long state, unsigned long long states_width);
public:
	generic_synthesis(input_table table, state_map state_map);
	std::vector<dnf> synth();
};