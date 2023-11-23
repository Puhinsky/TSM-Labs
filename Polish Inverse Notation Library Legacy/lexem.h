#pragma once

#include <bitset>

namespace polish_inverse
{
	class lexem
	{
	private:
		std::bitset<32> _value;
	public:
		lexem(unsigned int type, int code);

		int get_code() const;
		uint8_t get_type() const;
	};
}
