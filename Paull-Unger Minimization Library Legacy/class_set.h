#pragma once
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

namespace paull_unger
{
	typedef std::set<unsigned long long> state_class;

	struct class_compare
	{
		bool operator()(const state_class& lhs, const state_class& rhs) const;
	};

	typedef std::set<state_class> class_set;
	typedef std::set<state_class, class_compare> class_set_ordered;

	class_set union_set_state(const class_set& set, unsigned long long state);
	class_set union_set_set(const class_set& set_a, const class_set& set_b);
	class_set intersect_set_class(const class_set& set, const state_class& intersect_class);
	class_set reduce_set(const class_set& set);
}
