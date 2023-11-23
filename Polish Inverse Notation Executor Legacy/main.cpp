#include "../Polish Inverse Notation Library Legacy/abstract_sm.h"
#include "../Melee Struct Synthesis Library Legacy/table.h"
#include "../Polish Inverse Notation Library Legacy/translator.h"
#include "../Polish Inverse Notation Library Legacy/pic_translator.h"

using namespace::polish_inverse;
using namespace::melee_synthesis;

#define WORK_DIR "resources/"

#define F_TABLE_T_L WORK_DIR "f_table_t.txt"
#define G_TABLE_T_L WORK_DIR "g_table_t.txt"
#define F_TABLE_C_L WORK_DIR "f_table_c.txt"
#define G_TABLE_C_L WORK_DIR "g_table_c.txt"
#define INPUT_L WORK_DIR "input.txt"
#define OUTPUT_S WORK_DIR "output.txt"

int main()
{
	table f_table_t;
	table g_table_t;
	table f_table_c;
	table g_table_c;

	f_table_t.load(F_TABLE_T_L);
	g_table_t.load(G_TABLE_T_L);
	f_table_c.load(F_TABLE_C_L);
	g_table_c.load(G_TABLE_C_L);

	abstract_sm translation_sm(0, f_table_t, g_table_t);
	abstract_sm pic_translation_sm(0, f_table_c, g_table_c);

	translator translator(translation_sm, INPUT_L);
	pic_translator pic_translator(pic_translation_sm);

	auto lexems = translator.run();
	auto pic_lexems = pic_translator.run(lexems);

	return 0;
}