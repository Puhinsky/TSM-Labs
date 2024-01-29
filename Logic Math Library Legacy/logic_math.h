#pragma once

namespace logic_math 
{
	unsigned int ones_count(unsigned long long number);
	unsigned long long apply_bit_mask(unsigned long long value, unsigned long long mask);
	bool get_bit(unsigned long long value, unsigned long long bit_number);
	unsigned int log2_int(unsigned long long x);
	unsigned long long pow2(unsigned int value);
	unsigned long long concat_values(unsigned long long high, unsigned long long low, unsigned int shift);
}