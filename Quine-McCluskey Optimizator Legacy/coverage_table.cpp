#include "coverage_table.h"

bool less_than_sdnf(const std::pair<minterm, row>& lhs, const std::pair<minterm, row>& rhs)
{
	return lhs.second.size() < rhs.second.size();
}

bool less_than_tdnf(const std::pair<minterm, unsigned int>& lhs, const std::pair<minterm, unsigned int>& rhs)
{
	return lhs.second < rhs.second;
}

table coverage_table::build_table()
{
	table table;

	for (auto& sdnf_term : _sdnf)
	{
		row tdnf_terms;

		for (auto& tdnf_term : _tdnf)
		{
			auto intersects_count = 0;

			if (sdnf_term.has_intersect(tdnf_term))
			{
				for (auto& sub_sdnf_term : _sdnf)
				{
					if (sub_sdnf_term.has_intersect(tdnf_term))
						intersects_count++;
				}

				tdnf_terms.insert({ tdnf_term, intersects_count });
			}
		}

		if (tdnf_terms.size() != 0)
			table.insert({ sdnf_term, tdnf_terms });
	}

	return table;
}

void coverage_table::erase_sdnf_by_tdnf(const minterm& tdnf_term)
{
	for (auto it = _sdnf.begin(); it != _sdnf.end();)
	{
		if ((*it).has_intersect(tdnf_term))
			_sdnf.erase(it++);
		else
			++it;
	}
}

coverage_table::coverage_table(minterms_set rows, minterms_set columns)
{
	_tdnf = rows;
	_sdnf = columns;
}

minterms_set coverage_table::get_nonreduntant()
{
	minterms_set nonredundant;

	while (_sdnf.size() > 0 && _tdnf.size() > 0)
	{
		auto table = build_table();
		auto& min_sdnf_column = *min_element(table.begin(), table.end(), less_than_sdnf);
		auto& max_tdnf_row = *max_element(min_sdnf_column.second.begin(), min_sdnf_column.second.end(), less_than_tdnf);
		nonredundant.insert(max_tdnf_row.first);
		_tdnf.erase(max_tdnf_row.first);
		erase_sdnf_by_tdnf(max_tdnf_row.first);
	}

	return nonredundant;
}