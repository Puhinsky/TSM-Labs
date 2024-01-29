#include "table.h"

using namespace::melee_synthesis;

void table::update_size()
{
	_height = _table.size();
	_width = _table[0].size();
}

table::table()
{
	_height = 0;
	_width = 0;
}

table::table(unsigned long long width, unsigned long long height)
{
	set_size(width, height);
}

void table::set_size(unsigned long long width, unsigned long long height)
{
	_table.resize(height);

	for (auto& row : _table)
	{
		row.resize(width);
	}

	update_size();
}

void table::load(std::string file_path)
{
	_table.clear();
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
	update_size();
}

void table::print(std::ostream& os)
{
	for (const auto& row : _table)
	{
		for (const auto& value : row)
		{
			if (value.get_type() == TV_VALUE)
				os << value.get_value();
			else
				os << '-';

			os << ' ';
		}

		os << '\n';
	}
}

void table::save(std::string file_path)
{
	std::ofstream os(file_path);
	print(os);
	os.close();
}

void melee_synthesis::table::set_value(unsigned long long row, unsigned long long column, table_value value)
{
	_table[row][column] = value;
}

table_value table::get_value(unsigned long long row, unsigned long long column) const
{
	return _table[row][column];
}

unsigned long long table::get_width() const
{
	return _width;
}

unsigned long long table::get_height() const
{
	return _height;
}

