#pragma once
#include "minterm_set.h"
#include "minterm.h"
#include <unordered_map>

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

