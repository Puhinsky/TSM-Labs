export module dnf_writer;

import <string>;
import <fstream>;
import dnf;

export void write_dnf(const dnf& dnf, std::string file_path)
{
	std::ofstream os(file_path);
	dnf.print(os);
	os.close();
}