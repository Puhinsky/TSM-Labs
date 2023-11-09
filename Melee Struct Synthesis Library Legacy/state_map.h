#pragma once
#include <unordered_map>

namespace melee_synthesis
{
	class state_map
	{
	private:
		std::unordered_map<unsigned long long, unsigned long long> _decode_map;
		std::unordered_map<unsigned long long, unsigned long long> _code_map;

	public:
		state_map();

		void define(unsigned long long state, unsigned long long number);
		unsigned long long code(unsigned long long number);
		unsigned long long decode(unsigned long long state);
	};
}
