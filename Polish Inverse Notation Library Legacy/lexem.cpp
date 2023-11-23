#include "lexem.h"

using namespace::std;

polish_inverse::lexem::lexem(unsigned int type, int code)
{
	_value = bitset<32>(type << 30) | bitset<32>(code);
}
 
int polish_inverse::lexem::get_code() const
{
	string s = _value.to_string().substr(3, 31);

	return static_cast<int>(bitset<30>{ s }.to_ulong());
}

uint8_t polish_inverse::lexem::get_type() const
{
	string s = _value.to_string().substr(0, 2);

	return static_cast<uint8_t>(bitset<2>{ s }.to_ulong());
}
