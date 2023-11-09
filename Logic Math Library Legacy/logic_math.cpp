#include "logic_math.h"

unsigned int logic_math::ones_count(unsigned long long number)
{
	unsigned long long bit = 1;
	unsigned int counter = 0;

	while (bit <= number)
	{
		if (bit & number)
			counter++;

		bit <<= 1;
	}

	return counter;
}

unsigned long long logic_math::apply_bit_mask(unsigned long long value, unsigned long long mask)
{
	return value & mask;
}

bool logic_math::get_bit(unsigned long long value, unsigned long long bit_number)
{
	unsigned long long mask = (unsigned long long)1 << bit_number;

	return apply_bit_mask(value, mask) == mask;
}

unsigned int logic_math::log2_int(unsigned long long x)
{
	if (x <= 1) return 0;

	unsigned int result = 0;
	unsigned int value = 1;

	while (value < x)
	{
		value <<= 1;
		result++;
	}

	return result;
}

unsigned long long logic_math::pow2(unsigned int value)
{
	return (unsigned long long)1 << value;
}

unsigned long long logic_math::concat_values(unsigned long long high, unsigned long long low, unsigned int shift)
{
	return (high << shift) + low;
}