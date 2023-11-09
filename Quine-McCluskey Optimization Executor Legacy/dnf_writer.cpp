#include "dnf_writer.h"

using namespace::quine_mc_cluskey;

void write_dnf(const dnf& dnf, std::string file_path)
{
	std::ofstream os(file_path);
	dnf.print(os);
	os.close();
}