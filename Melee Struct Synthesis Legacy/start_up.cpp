#include "input_table.h"
#include "struct_synthesis.h"
#include <iostream>
#include "synth_writer.h"

int main()
{
	input_table f_table("f_table.txt");
	input_table g_table("g_table.txt");

	struct_synthesis synthesis(f_table, g_table);

	auto triggers = synthesis.synth_triggers();
	auto outs = synthesis.synth_outs();

	write_synth_to_console(triggers, outs);
	write_synth_to_file(triggers, outs, "output.txt");

	return 0;
}