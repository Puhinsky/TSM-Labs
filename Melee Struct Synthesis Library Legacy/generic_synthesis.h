#pragma once
#include "table.h"
#include "state_map.h"
#include "../Quine-McCluskey Optimization Library Legacy/minterm_set.h"
#include "../Quine-McCluskey Optimization Library Legacy/dnf.h"

namespace qmcc = quine_mc_cluskey;

namespace melee_synthesis
{
	class generic_synthesis
	{
	private:
		std::vector<qmcc::dnf> get_dnfs();
		unsigned long long get_terms_count();

	protected:
		table _table;
		state_map _state_map;
		std::vector<qmcc::minterms_set> minterms_sets;
		unsigned int _triggers_count;

		virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value) = 0;
		virtual void on_table_undetermined(unsigned long long row, unsigned long long column) = 0;

		unsigned long long get_minterm_number(unsigned long long input, unsigned long long state);

	public:
		generic_synthesis(table table, state_map state_map);

		std::vector<qmcc::dnf> synth();
	};
}