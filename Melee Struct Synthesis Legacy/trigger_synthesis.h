#pragma once
#include "generic_synthesis.h"

class trigger_synthesis : public generic_synthesis
{
private:
	void init_sdnfs()
	{
		for (auto i = 0; i < _triggers_count; i++)
			minterms_sets.push_back(minterms_set());
	}

protected:
	virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_state);
	virtual void on_table_undetermined(unsigned long long row, unsigned long long column);
public:
	trigger_synthesis(input_table table, state_map state_map) : generic_synthesis(table, state_map)
	{
		init_sdnfs();
	}
};

