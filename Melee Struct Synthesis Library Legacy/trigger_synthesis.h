#pragma once
#include "generic_synthesis.h"

namespace melee_synthesis
{
	class trigger_synthesis : public generic_synthesis
	{
	private:
		void init_sdnfs();

	protected:
		virtual void on_table_value(unsigned long long row, unsigned long long column, unsigned long long raw_value);
		virtual void on_table_undetermined(unsigned long long row, unsigned long long column);
	public:
		trigger_synthesis(table table, state_map state_map) : generic_synthesis(table, state_map)
		{
			init_sdnfs();
		}
	};
}
