#include "input_table.h"

input_table::input_table()
{
	_height = 0;
	_width = 0;
}

input_table::input_table(std::string file_path)
{
	std::ifstream is(file_path);
	std::string line;

	while (getline(is, line))
	{
		std::vector<table_value> row;
		std::istringstream iss(line);
		std::string element;

		while (iss >> element)
		{
			if (!element.empty())
			{
				table_value value(element);
				row.push_back(value);
			}
		}

		_table.push_back(row);
	}

	is.close();
	_height = _table.size();
	_width = _table[0].size();
}

unsigned long long input_table::get_width()
{
	return _width;
}

unsigned long long input_table::get_height()
{
	return _height;
}

table_value input_table::get_value(unsigned long long row, unsigned long long column)
{
	return _table[row][column];
}
