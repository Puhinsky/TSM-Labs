#include "min_coverage_finder.h"

using namespace::std;
using namespace::paull_unger;
using namespace::melee_synthesis;

std::unordered_set<unsigned long long> paull_unger::min_coverage_finder::find_unique_states()
{
	map<unsigned long long, unsigned long long> unique_weights;
	unordered_set<unsigned long long> unique_states;

	for (const auto& state_class : _classes)
	{
		for (const auto& state : state_class)
		{
			unique_weights.insert({ state, 0 });
		}
	}

	for (const auto& state_class : _classes)
	{
		for (auto& state : unique_weights)
		{
			if (state_class.find(state.first) != state_class.cend())
				state.second++;
		}
	}

	unsigned long long min_times = (*min_element(unique_weights.begin(), unique_weights.end(), [](const auto& l, const auto& r) { return l.second < r.second; })).second;

	for (const auto& state : unique_weights)
	{
		if (state.second == min_times)
			unique_states.insert(state.first);
	}

	return unique_states;
}

state_class paull_unger::min_coverage_finder::find_unique_class(std::unordered_set<unsigned long long> unique_states)
{
	for (const auto& state_class : _classes)
	{
		for (const auto& unique_state : unique_states)
		{
			if (state_class.find(unique_state) != state_class.cend())
				return state_class;
		}
	}

	return state_class();
}

bool paull_unger::min_coverage_finder::try_find_new_class(unsigned long long input, state_class& current_class, const class_set& exist_classes)
{
	state_class min_class;
	
	for (auto state : current_class)
	{
		auto value = _f_table.get_value(input, state - 1);

		if (value.get_type() == TV_VALUE)
			min_class.insert(value.get_value());
	}

	for (auto class_a : exist_classes)
	{
		if (includes(class_a.begin(), class_a.end(), min_class.begin(), min_class.end()))
		{
			current_class = class_a;

			return false;
		}
	}

	for (auto class_a : _classes)
	{
		if (includes(class_a.begin(), class_a.end(), min_class.begin(), min_class.end()))
		{
			current_class = class_a;

			return true;
		}
	}

	return false;
}

bool paull_unger::min_coverage_finder::try_expand_coverage(state_class& current_class, class_set& exist_classes)
{
	bool is_expanded = false;

	for (unsigned long long input = 0; input < _f_table.get_width(); input++)
	{
		if (try_find_new_class(input, current_class, exist_classes))
		{
			is_expanded = true;
			exist_classes.insert(current_class);
		}
	}

	return is_expanded;
}

paull_unger::min_coverage_finder::min_coverage_finder(ms::table f_table)
{
	_f_table = f_table;
}

class_set_ordered paull_unger::min_coverage_finder::find(class_set_ordered max_classes)
{
	_classes = max_classes;
	class_set new_classes;

	auto unique_states = find_unique_states();
	auto unique_class = find_unique_class(unique_states);
	new_classes.insert(unique_class);


	while (try_expand_coverage(unique_class, new_classes))
	{

	}

	return _classes;
}
