#pragma once
#include "minterm_set.h"
#include "minterm.h"
#include <unordered_map>

namespace quine_mc_cluskey 
{
	typedef std::unordered_map<minterm, unsigned int, minterm::hash> row;
	typedef std::unordered_map<minterm, row, minterm::hash> table;

	class coverage_table
	{
	private:
		minterms_set _tdnf;
		minterms_set _sdnf;

		table build_table();
		void erase_sdnf_by_tdnf(const minterm& tdnf_term);

	public:
		coverage_table(minterms_set rows, minterms_set columns);

		minterms_set get_nonreduntant();
	};

	bool less_than_sdnf(const std::pair<minterm, row>& lhs, const std::pair<minterm, row>& rhs);
	bool less_than_tdnf(const std::pair<minterm, unsigned int>& lhs, const std::pair<minterm, unsigned int>& rhs);
}
