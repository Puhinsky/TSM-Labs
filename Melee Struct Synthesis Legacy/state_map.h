#pragma once
#include <unordered_map>

class state_map
{
private:
	std::unordered_map<unsigned long long, unsigned long long> _map;
public:
	state_map();
	void code(unsigned long long state, unsigned long long number);
	unsigned long long decode(unsigned long long number);
};

