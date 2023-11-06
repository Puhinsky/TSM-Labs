#include "minterm.h"

size_t minterm::hash::operator()(const minterm& other) const
{
	return std::hash<unsigned long long>()(other._number)
		^ std::hash<unsigned long long>()(other._index)
		^ std::hash<unsigned long long>()(other._pointer);
}

void minterm::calculate_index()
{
	_index = ones_count(_number);
}

bool minterm::can_concat(const minterm& other) const
{
	return _number < other._number
		&& _pointer == other._pointer
		&& other._index - _index == 1
		&& ones_count(other._number - _number) == 1;
}

minterm::minterm()
{
	_logic = TRUE;
	_number = 0;
	_pointer = 0;
	_index = 0;
	_is_concated = false;
}

minterm::minterm(unsigned long long number, logic_value logic)
{
	_logic = logic;
	_number = number;
	_pointer = 0;
	_is_concated = false;
	calculate_index();
}

bool minterm::try_concat(const minterm& other, minterm& out) const
{
	if (can_concat(other))
	{
		out._logic = other._logic;
		out._number = _number;
		out._index = _index;
		out._pointer = _pointer + other._number - _number;
		out._is_concated = false;
		_is_concated = true;
		other._is_concated = true;

		return true;
	}

	return false;
}

bool minterm::is_concated() const
{
	return _is_concated;
}

bool minterm::is_undetermined() const
{
	return _logic == UNDETERMINED;
}

bool minterm::has_intersect(const minterm& other) const
{
	return (_number & ~other._pointer) == other._number;
}

bool minterm::operator==(const minterm& other) const
{
	return _number == other._number
		&& _index == other._index
		&& _pointer == other._pointer;
}

void minterm::print(std::ostream& os, unsigned long long terms_count) const
{
	unsigned long long bit = terms_count >> 1;

	while (bit != 0)
	{
		if (apply_bit_mask(bit, _pointer) == bit)
			os << "-";
		else
			os << (apply_bit_mask(bit, _number) == bit);

		bit >>= 1;
	}
}