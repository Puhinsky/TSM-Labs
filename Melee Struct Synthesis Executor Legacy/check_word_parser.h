#pragma once
#include <vector>
#include "../Melee Struct Synthesis Library Legacy/table_value.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"

namespace ms = melee_synthesis;

class check_word_parser
{
private:
	std::vector<unsigned long long> _inputs;
	std::vector<ms::table_value> _states;
	std::vector<ms::table_value> _outs;

public:
	check_word_parser(std::string file_path);

	std::vector<unsigned long long> get_inputs();
	std::vector<ms::table_value> get_states();
	std::vector<ms::table_value> get_outs();
};

