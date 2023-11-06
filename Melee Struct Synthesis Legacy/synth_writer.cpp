#include "synth_writer.h"
#include "melee_machine.h"

void write_synth(melee_machine& synth, std::string file_path)
{
	std::ofstream os(file_path);
	synth.print(os);
	os.close();
}
