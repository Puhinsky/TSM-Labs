#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Paull-Unger Minimization Library Legacy/pre_comp_table.h"

using namespace::melee_synthesis;
using namespace::paull_unger;

#define WORK_DIR "resources/"

#define F_TABLE_L WORK_DIR "f_table.txt"
#define G_TABLE_L WORK_DIR "g_table.txt"

int main()
{
	table f_table;
	table g_table;

	f_table.load(F_TABLE_L);
	g_table.load(G_TABLE_L);

	pre_comp_table table(f_table, g_table);
	table.solve();

	return 0;
}