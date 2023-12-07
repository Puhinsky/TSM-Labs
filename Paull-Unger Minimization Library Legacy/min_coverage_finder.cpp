#include "min_coverage_finder.h"

using namespace::std;
using namespace::paull_unger;
using namespace::melee_synthesis;

state_class paull_unger::min_coverage_finder::get_min_class(unsigned long long input, state_class current_class)
{
	state_class min_class;

	for (auto state : current_class)
	{
		auto value = _f_table.get_value(input, state - 1);

		if (value.get_type() == TV_VALUE)
			min_class.insert(value.get_value());
	}

	return min_class;
}

bool paull_unger::min_coverage_finder::try_find_class_from_exists(const state_class& min_class, state_class& finded_class)
{
	for (const auto& class_a : _exists_coverage)
	{
		if (includes(class_a.begin(), class_a.end(), min_class.begin(), min_class.end()))
		{
			finded_class = class_a;

			return true;
		}
	}

	return false;
}

bool paull_unger::min_coverage_finder::try_find_class_from_all(const state_class& min_class, state_class& finded_class)
{
	for (const auto& class_a : _classes)
	{
		if (includes(class_a.begin(), class_a.end(), min_class.begin(), min_class.end()))
		{
			finded_class = class_a;

			return true;
		}
	}

	return false;
}

std::set<unsigned long long> paull_unger::min_coverage_finder::find_unique_states()
{
	map<unsigned long long, unsigned long long> unique_weights;
	set<unsigned long long> unique_states;

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

state_class paull_unger::min_coverage_finder::find_unique_class(std::set<unsigned long long> unique_states)
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

void paull_unger::min_coverage_finder::expand(state_class current_class, std::set<state_class>& feedback)
{
	vector<state_class> states;

	for (unsigned long long input = 0; input < _f_table.get_height(); input++)
	{
		expand_by_input(input, current_class, states, feedback);
	}

	_coverage.insert({ current_class, states });
}

void paull_unger::min_coverage_finder::expand_by_input(unsigned long long input, state_class current_class, std::vector<state_class>& class_states, std::set<state_class>& feedback)
{
	state_class min_class = get_min_class(input, current_class);

	if (min_class.size() == 0)
	{
		class_states.push_back(state_class());

		return;
	}

	state_class input_class;

	if (!try_find_class_from_exists(min_class, input_class))
	{
		try_find_class_from_all(min_class, input_class);
		_exists_coverage.insert(input_class);
		feedback.insert(input_class);
	}

	class_states.push_back(input_class);
}

paull_unger::min_coverage_finder::min_coverage_finder(ms::table f_table)
{
	_f_table = f_table;
}

std::map<state_class, std::vector<state_class>> min_coverage_finder::find(class_set_ordered max_classes)
{
	_classes = max_classes;
	_new_classes = {};

	auto unique_states = find_unique_states();
	auto unique_class = find_unique_class(unique_states);
	_new_classes.insert(unique_class);

	set<state_class> classes_from_expand;
	classes_from_expand.insert(unique_class);
	_exists_coverage.insert(unique_class);


	while (classes_from_expand.size() > 0)
	{
		set<state_class> new_classes_from_expand;

		for (const auto& state_class : classes_from_expand)
		{
			expand(state_class, new_classes_from_expand);
		}

		classes_from_expand = new_classes_from_expand;
	}

	return _coverage;
}