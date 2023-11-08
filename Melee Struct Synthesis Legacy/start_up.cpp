#include "input_table.h"
#include "struct_synthesis.h"
#include <iostream>
#include "synth_writer.h"
#include "check_word_parser.h"
#include "simulator.h"
#include "check_word_writer.h"

int main()
{
	input_table f_table("f_table_v2.txt");
	input_table g_table("g_table_v2.txt");
	check_word_parser check_word("check_word_v2.txt");

	struct_synthesis synthesis(f_table, g_table);
	auto melee_machine = synthesis.synth();

	melee_machine.print(std::cout);
	write_synth(melee_machine, "output_v2.txt");

	simulator simulator(melee_machine, check_word.get_inputs(), check_word.get_states()[0].get_value());
	simulator.simulate();

	write_check_word(check_word.get_inputs(), simulator.get_states(), simulator.get_outs(), "check_v2.txt");

	return 0;
}