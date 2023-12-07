#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Paull-Unger Minimization Library Legacy/primary_compability_solver.h"
#include "../Paull-Unger Minimization Library Legacy/full_compability_solver.h"
#include "../Paull-Unger Minimization Library Legacy/max_classes_solver.h"
#include <iostream>
#include "../Paull-Unger Minimization Library Legacy/min_coverage_finder.h"
#include "../Paull-Unger Minimization Library Legacy/fsm_builder.h"
#include "../Polish Inverse Notation Library Legacy/abstract_sm.h"
#include "../Paull-Unger Minimization Library Legacy/abstract_simulator.h"

using namespace::melee_synthesis;
using namespace::paull_unger;
using namespace::polish_inverse;

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
	std::cout << '\n';
	g_table_min.print(std::cout);
	std::cout << '\n';

	//CHECK
	std::vector<unsigned long long> check_word{ 3, 1, 2, 3, 2, 3 };
	abstract_sm defaut_sm(1, f_table, g_table, false);
	abstract_sm min_sm(1, f_table_min, g_table_min, false);

	abstract_simulator default_simulator(defaut_sm);
	abstract_simulator min_simulator(min_sm);

	default_simulator.simulate(check_word, 1);
	min_simulator.simulate(check_word, 1);

	default_simulator.get_report().print(std::cout);
	std::cout << '\n';
	min_simulator.get_report().print(std::cout);

	return 0;
}