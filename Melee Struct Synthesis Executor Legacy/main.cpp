#include <iostream>
#include "check_word_parser.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Melee Struct Synthesis Library Legacy/struct_synthesis.h"
#include "../Melee Struct Synthesis Library Legacy/simulator.h"

using namespace::melee_synthesis;

#define WORK_DIR "resources/"

#define F_TABLE_L WORK_DIR "f_table_v1.txt"
#define G_TABLE_L WORK_DIR "g_table_v1.txt"
#define CHECK_WORD_L WORK_DIR "check_word_v1.txt"
#define SYNTH_S WORK_DIR "output_v1.txt"
#define CHECK_WORD_S WORK_DIR "check_v1.txt"

int main()
{
	table f_table;
	table g_table;
	check_word_parser check_word(CHECK_WORD_L);

	f_table.load(F_TABLE_L);
	g_table.load(G_TABLE_L);

	struct_synthesis synthesis(f_table, g_table);
	auto melee_machine = synthesis.synth();

	simulator simulator(melee_machine, check_word.get_inputs(), check_word.get_states()[0].get_value());
	auto synth_check_word = simulator.simulate();

	melee_machine.print(std::cout);
	melee_machine.save(SYNTH_S);
	synth_check_word.save(CHECK_WORD_S);

	return 0;
}