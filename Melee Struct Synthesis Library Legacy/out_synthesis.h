#pragma once
#include "generic_synthesis.h"

namespace melee_synthesis
{
	class out_synthesis : public generic_synthesis
	{
	private:
		std::unordered_set<unsigned long long> _outs;

		void init_sdnfs();
		void define_outs();

	protected:
		virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value);
		virtual void on_table_undetermined(unsigned long long row, unsigned long long column);

	public:
		out_synthesis(table table, state_map state_map) : generic_synthesis(table, state_map)
		{
			define_outs();
			init_sdnfs();
		}
	};
}
