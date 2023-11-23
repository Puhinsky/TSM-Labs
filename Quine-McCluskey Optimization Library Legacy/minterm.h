#pragma once
#include "logic_value.h"
#include "../Logic Math Library Legacy/logic_math.h"
#include <ostream>

namespace quine_mc_cluskey
{
	class minterm
	{
	private:
		logic_value _logic;

		unsigned long long _number;
		unsigned int _index;
		unsigned long long _pointer;
		mutable bool _is_concated;

		void calculate_index();
		bool can_concat(const minterm& other) const;

	public:
		minterm();
		minterm(unsigned long long number, logic_value logic);

		bool try_concat(const minterm& other, minterm& out) const;
		bool is_concated() const;
		bool is_undetermined() const;
		bool has_intersect(const minterm& other) const;
		bool calculate_function(unsigned long long value) const;
		void print(std::ostream& os, unsigned long long terms_count) const;

		bool operator == (const minterm& other) const;

		struct hash
		{
			size_t operator()(const minterm& value) const;
		};
	};
}
