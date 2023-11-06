export module state_map;

import <vector>;

export class state_map
{
private:
	bool _reversed;
	std::vector<unsigned long long> _decode_map;
public:
	state_map(bool reversed = false);
	void code(unsigned long long state);
	unsigned long long decode(unsigned long long number);
};

state_map::state_map(bool reversed)
{
	_reversed = reversed;
}

void state_map::code(unsigned long long state)
{
	if (_reversed)
		_decode_map.insert(_decode_map.begin(), state);
	else
		_decode_map.push_back(state);
}

unsigned long long state_map::decode(unsigned long long number)
{
	return _decode_map[number];
}
