#include "state_map.h"

state_map::state_map()
{}

void state_map::define(unsigned long long state, unsigned long long number)
{
	_decode_map[state] = number;
	_code_map[number] = state;
}

unsigned long long state_map::code(unsigned long long number)
{
	return _code_map[number];
}

unsigned long long state_map::decode(unsigned long long state)
{
	return _decode_map[state];
}