#include <iostream>
#include "dnf_reader.h"
#include "dnf_writer.h"

#define WORK_DIR "resources/"

#define INPUT_L WORK_DIR "input.txt"
#define OUTPUT_S WORK_DIR "output.txt"

int main()
{
	auto dnf = read_dnf(INPUT_L);
	std::cout << "origin:\t";
	dnf.print_function(std::cout);

	while (dnf.try_min_to_tdnf()) {}

	dnf.min_to_mdnf();
	std::cout << "\nmin:\t";
	dnf.print_function(std::cout);

	std::cout << "\n\n";
	dnf.print(std::cout);
	dnf.save(OUTPUT_S);

	return 0;
}