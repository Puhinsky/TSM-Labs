#include "state_pair.h"

state_pair::state_pair()
{}

state_pair::state_pair(std::pair<ms::table_value, ms::table_value> pair)
{
    _pair = pair;
}

bool state_pair::is_compatible_internal() const
{
    return _pair.first == _pair.second;
}

bool state_pair::operator==(const state_pair& other) const
{
    return (_pair.first == other._pair.first && _pair.second == other._pair.second)
        || (_pair.first == other._pair.second && _pair.second == other._pair.first);
}

size_t state_pair::hash::operator()(const state_pair& pair) const
{
    return pair._pair.first.get_hash() ^ pair._pair.second.get_hash();
}
