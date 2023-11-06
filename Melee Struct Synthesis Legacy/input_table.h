#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "table_value.h"

class input_table
{
private:
	std::vector<std::vector<table_value>> _table;
	unsigned long long _width;
	unsigned long long _height;
public:
	input_table();
	input_table(std::string file_path);
	unsigned long long get_width();
	unsigned long long get_height();
	table_value get_value(unsigned long long row, unsigned long long column);
};

