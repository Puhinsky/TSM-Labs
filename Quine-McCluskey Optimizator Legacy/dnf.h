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
	dnf(minterms_set minterms, unsigned long long terms_count);

	bool try_min_to_tdnf();
	void min_to_mdnf();
	void print(std::ostream& os) const;

};

