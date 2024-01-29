#include "lexem.h"

using namespace::std;

polish_inverse::lexem::lexem(uint8_t type, int code)
{
	_type = type;
	_code = code;
}
 
int polish_inverse::lexem::get_code() const
{
	return _code;
}

uint8_t polish_inverse::lexem::get_type() const
{
	return _type;
}
