#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Paull-Unger Minimization Library Legacy/primary_compability_solver.h"
#include "../Paull-Unger Minimization Library Legacy/full_compability_solver.h"
#include "../Paull-Unger Minimization Library Legacy/max_classes_solver.h"
#include <iostream>
#include "../Paull-Unger Minimization Library Legacy/min_coverage_finder.h"
#include "../Paull-Unger Minimization Library Legacy/fsm_builder.h"

using namespace::melee_synthesis;
using namespace::paull_unger;

#define WORK_DIR "resources/"

#define F_TABLE_L WORK_DIR "f_table1.txt"
#define G_TABLE_L WORK_DIR "g_table1.txt"

int main()
{
	table f_table;
	table g_table;

	f_table.load(F_TABLE_L);
	g_table.load(G_TABLE_L);

	primary_compability_solver primary_solver(f_table, g_table);
	auto primary_table = primary_solver.solve();

	full_compability_solver full_solver(f_table);
	auto full_table = full_solver.solve(primary_table);

	max_classes_solver max_classes_solver;
	auto max_classes = max_classes_solver.solve(full_table);

	min_coverage_finder min_coverage(f_table);
	auto min_class_set = min_coverage.find(max_classes);

	fsm_builder builder(min_class_set, g_table);
	auto f_table_min = builder.build_states_table();
	auto g_table_min = builder.build_outs_table();

	f_table_min.print(std::cout);
	g_table_min.print(std::cout);

	return 0;
}