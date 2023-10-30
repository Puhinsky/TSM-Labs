export module dnf_reader;

import <string>;
import <vector>;
import <map>;
import <fstream>;
import dnf;
import logic_value;
import minterms_set;

std::map<char, logic_value> logic_map = {
	{'0', FALSE},
	{'1', TRUE},
	{'-', UNDETERMINED}
};

std::string read_line(std::string file_path, unsigned int line_number)
{
	std::ifstream is(file_path);
	std::string line;

	for (auto i = 0; i <= line_number; ++i)
	{
		getline(is, line);
	}

	is.close();

	return line;
}

std::vector<logic_value> parse(std::string value)
{
	std::vector<logic_value> function;

	for (auto symbol : value)
	{
		function.push_back(logic_map[symbol]);
	}

	return function;
}

dnf get_dnf(std::vector<logic_value> function)
{
	minterms_set minterms;

	for (auto i = 0; i < function.size(); ++i)
	{
		auto term = function[i];

		if (term == TRUE or term == UNDETERMINED)
			minterms.insert(minterm(i, term));
	}

	return dnf(minterms, function.size());
}

export dnf read_dnf(std::string file_path)
{
	return get_dnf(parse(read_line(file_path, 0)));
}