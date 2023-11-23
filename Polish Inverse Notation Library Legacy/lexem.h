#pragma once

#include <bitset>

namespace polish_inverse
{
	class lexem
	{
	private:
		uint8_t _type;
		int _code;
	public:
		lexem(uint8_t type, int code);

		uint8_t get_type() const;
		int get_code() const;
	};
}
