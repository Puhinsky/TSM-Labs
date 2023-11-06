#include "state_map.h"

state_map::state_map()
{}

void state_map::code(unsigned long long state, unsigned long long number)
{
	_map[state] = number;
}

unsigned long long state_map::decode(unsigned long long state)
{
	return _map[state];
}