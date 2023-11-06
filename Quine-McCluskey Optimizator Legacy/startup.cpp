#include "dnf_reader.h"
#include "dnf_writer.h"
#include <iostream>

int main()
{
	auto dnf = read_dnf("input.txt");

	while (dnf.try_min_to_tdnf()) {}

	dnf.min_to_mdnf();

	dnf.print(std::cout);
	write_dnf(dnf, "output.txt");

	return 0;
}