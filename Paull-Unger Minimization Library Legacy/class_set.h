#pragma once
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

namespace paull_unger
{
	typedef std::set<unsigned long long> state_class;
	typedef std::set<state_class> class_set;

	class_set union_set_state(const class_set& set, unsigned long long state);
	class_set union_set_set(const class_set& set_a, const class_set& set_b);
	class_set intersect_set_class(const class_set& set, const state_class& intersect_class);
}

