#pragma once
#include "minterm_set.h"
#include "coverage_table.h"

class dnf
{
private:
	unsigned long long _terms_count;
	minterms_set _minterms;
	minterms_set _sdnf;

public:
	dnf(minterms_set minterms, unsigned long long terms_count)
	{
		_terms_count = terms_count;
		_minterms = minterms;

		for (auto& minterm : _minterms)
		{
			if (!minterm.is_undetermined())
				_sdnf.insert(minterm);
		}
	}

	bool try_min_to_tdnf()
	{
		minterms_set minimized;
		bool is_minimized = false;

		for (auto& minterm_a : _minterms)
		{
			for (auto& minterm_b : _minterms)
			{
				minterm concated;

				if (minterm_a.try_concat(minterm_b, concated))
				{
					minimized.insert(concated);
					is_minimized = true;
				}
			}
		}

		for (const auto& minterm : _minterms)
		{
			if (!minterm.is_concated())
				minimized.insert(minterm);
		}

		_minterms = minimized;

		return is_minimized;
	}

	void min_to_mdnf()
	{
		coverage_table table(_minterms, _sdnf);
		_minterms = table.get_nonreduntant();
	}

	void print(std::ostream& os) const
	{
		for (const auto& minterm : _minterms)
		{
			minterm.print(os, _terms_count);
			os << '\n';
		}
	}

	//lab 2
	bool calculate_function(unsigned long long value)
	{
		bool result = false;

		for (auto& minterm : _minterms)
		{
			result |= minterm.calculate_function(value);
		}

		return result;
	}
};

