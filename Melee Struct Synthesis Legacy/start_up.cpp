#include "input_table.h"
#include "struct_synthesis.h"
#include <iostream>
#include "synth_writer.h"

int main()
{
	input_table f_table("f_table.txt");
	input_table g_table("g_table.txt");
	input_table check_word("check_word.txt");

	struct_synthesis synthesis(f_table, g_table);

	auto melee_machine = synthesis.synth();

	melee_machine.print(std::cout);
	write_synth(melee_machine, "output.txt");



	return 0;
}