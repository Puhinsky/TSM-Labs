#include "class_set.h"

using namespace::std;
using namespace::paull_unger;

class_set paull_unger::union_set_state(const class_set& set, unsigned long long state)
{
	class_set result;

	if (set.size() == 0)
	{
		result.insert(state_class{ state });
	}
	else
	{
		for (const auto& existing_class : set)
		{
			state_class new_class;
			new_class.insert(state);

			for (const auto& existing_state : existing_class)
			{
				new_class.insert(existing_state);
			}

			result.insert(new_class);
		}
	}

	return result;
}

class_set paull_unger::union_set_set(const class_set& set_a, const class_set& set_b)
{
	class_set result;
	set_union(set_a.cbegin(), set_a.cend(), set_b.cbegin(), set_b.cend(), inserter(result, result.begin()));

	return result;
}

class_set paull_unger::intersect_set_class(const class_set& set, const state_class& intersect_class)
{
	class_set result;

	for (const auto& existing_class : set)
	{
		state_class new_class;
		set_intersection(existing_class.cbegin(), existing_class.cend(), intersect_class.cbegin(), intersect_class.cend(), inserter(new_class, new_class.begin()));

		if (new_class.size() > 0)
			result.insert(new_class);
	}

	return result;
}

class_set paull_unger::reduce_set(const class_set& set)
{
	class_set result;

	for (const auto& class_a : set)
	{
		for (const auto& class_b : set)
		{
			if (class_a == class_b)
				continue;

			if (includes(class_a.cbegin(), class_a.cend(), class_b.cbegin(), class_b.cend()))
			{
				result.insert(class_a);
				result.erase(class_b);
			}
			else
			{
				bool is_not_sub_set = true;

				for (const auto& class_c : result)
				{
					if (includes(class_c.cbegin(), class_c.cend(), class_b.cbegin(), class_b.cend()))
					{
						is_not_sub_set = false;

						break;
					}
				}

				if (is_not_sub_set)
					result.insert(class_b);
			}
		}
	}

	return result;
}

bool paull_unger::class_compare::operator()(const state_class& lhs, const state_class& rhs) const
{
	if (lhs.size() != rhs.size())
		return lhs.size() < rhs.size();
	else
		return lhs < rhs;
}
