#include "synth_writer.h"

void write_synth_to_file(std::vector<dnf> triggers, std::vector<dnf> outs, std::string file_path)
{
	std::ofstream os(file_path);
	write_dnfs_set(triggers, "Q", os);
	write_dnfs_set(outs, "y", os);
	os.close();
}

void write_synth_to_console(std::vector<dnf> triggers, std::vector<dnf> outs)
{
	write_dnfs_set(triggers, "Q", std::cout);
	write_dnfs_set(outs, "y", std::cout);
}

void write_dnfs_set(std::vector<dnf> dnfs, std::string prefix, std::ostream& os)
{
	for (auto i = 0; i < dnfs.size(); ++i)
	{
		os << prefix << i << '\n';
		dnfs[i].print(os);
	}

	os << '\n';
}
