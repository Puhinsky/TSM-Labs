#include "check_word_writer.h"

void write_check_word(std::vector<unsigned long long> inputs, std::vector<unsigned long long> states, std::vector<unsigned long long> outs, std::string file_path)
{
	std::ofstream os(file_path);

	auto max_lenght = std::max(inputs.size(), std::max(states.size(), outs.size()));

	for (auto i = 0; i < max_lenght; ++i)
	{
		if (i < inputs.size())
			os << inputs[i] << " ";
		else
			os << " ";

		if (i < states.size())
			os << states[i] << " ";
		else
			os << " ";

		if (i < outs.size())
			os << outs[i] << "\n";
	}

	os.close();
}
