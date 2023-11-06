#pragma once

inline unsigned int ones_count(unsigned long long number)
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

inline unsigned long long apply_bit_mask(unsigned long long value, unsigned long long mask)
{
	return value & mask;
}

inline bool get_bit(unsigned long long value, unsigned long long bit_number)
{
	unsigned long long mask = (unsigned long long)1 << bit_number;

	return apply_bit_mask(value, mask) == mask;
}

inline unsigned int log2_int(unsigned long long value)
{
	unsigned int result = 0;

	while (value >= 1)
	{
		value >>= 1;
		result++;
	}

	return result;
}

inline unsigned long long pow2(unsigned long long value)
{
	return (unsigned long long)1 << value;
}

