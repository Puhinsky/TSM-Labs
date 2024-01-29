#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "table_value.h"

namespace melee_synthesis
{
	class table
	{
	private:
		std::vector<std::vector<table_value>> _table;
		unsigned long long _width;
		unsigned long long _height;

		void update_size();

	public:
		table();
		table(unsigned long long width, unsigned long long height);
		void set_size(unsigned long long width, unsigned long long height);
		void load(std::string file_path);
		void print(std::ostream& os);
		void save(std::string file_path);
		void set_value(unsigned long long row, unsigned long long column, table_value value);
		table_value get_value(unsigned long long row, unsigned long long column) const;
		unsigned long long get_width() const;
		unsigned long long get_height() const;
	};
}
