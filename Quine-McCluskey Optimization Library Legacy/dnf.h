#pragma once
#include <fstream>
#include "minterm_set.h"
#include "coverage_table.h"

namespace quine_mc_cluskey
{
	class dnf
	{
	private:
		unsigned long long _terms_count;
		minterms_set _minterms;
		minterms_set _sdnf;

	public:
		dnf(minterms_set minterms, unsigned long long terms_count);

		bool try_min_to_tdnf();
		void min_to_mdnf();
		bool calculate_function(unsigned long long value) const;
		void print(std::ostream& os) const;
		void save(std::string file_path) const;
	};
}