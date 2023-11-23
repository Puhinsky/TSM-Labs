#pragma once
#include <vector>

class comp_table
{
private:
	std::vector<std::vector<bool>> _table;

public:
	comp_table(unsigned long long states_count);

	void set_value(bool value, unsigned long long stateA, unsigned long long stateB);
	bool get_value(unsigned long long stateA, unsigned long long stateB);
};

