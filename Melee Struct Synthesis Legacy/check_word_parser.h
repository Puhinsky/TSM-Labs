#pragma once
#include <string>
#include "input_table.h"

class check_word_parser
{
private:
	std::vector<unsigned long long> _inputs;
	std::vector<table_value> _states;
	std::vector<table_value> _outs;

public:
	check_word_parser(std::string file_path)
	{
		input_table _table(file_path);

		for (auto i = 0; i < _table.get_height(); ++i)
		{
			_inputs.push_back(_table.get_value(i, 0).get_value());
			_states.push_back(_table.get_value(i, 1));
			_outs.push_back(_table.get_value(i, 2));
		}
	}

	std::vector<unsigned long long> get_inputs()
	{

	}

	std::vector<table_value> get_states()
	{

	}

	std::vector<table_value> get_outs()
	{

	}
};

