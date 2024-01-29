#pragma once
#include "../Melee Struct Synthesis Library Legacy/table_value.h"

namespace ms = melee_synthesis;

class state_pair
{
private:
	std::pair<ms::table_value, ms::table_value> _pair;
public:
	state_pair();
	state_pair(std::pair<ms::table_value, ms::table_value> pair);
	bool is_compatible_internal() const;

	bool operator == (const state_pair& other) const;

	struct hash
	{
		size_t operator()(const state_pair& pair) const;
	};
};
