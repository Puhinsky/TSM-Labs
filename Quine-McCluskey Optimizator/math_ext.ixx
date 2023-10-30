export module math_ext;

export unsigned int ones_count(unsigned long long number)
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

export unsigned long long apply_bit_mask(unsigned long long value, unsigned long long mask)
{
	return value & mask;
}
