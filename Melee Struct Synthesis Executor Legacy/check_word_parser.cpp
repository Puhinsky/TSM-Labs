#include "check_word_parser.h"

using namespace::melee_synthesis;

check_word_parser::check_word_parser(std::string file_path)
{
	table table;
	table.load(file_path);

	for (auto i = 0; i < table.get_height(); ++i)
	{
		_inputs.push_back(table.get_value(i, 0).get_value());
		_states.push_back(table.get_value(i, 1));
		_outs.push_back(table.get_value(i, 2));
	}
}

std::vector<unsigned long long> check_word_parser::get_inputs()
{
	return _inputs;
}

std::vector<ms::table_value> check_word_parser::get_states()
{
	return _states;
}

std::vector<ms::table_value> check_word_parser::get_outs()
{
	return _outs;
}