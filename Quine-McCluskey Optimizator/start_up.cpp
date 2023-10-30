import dnf_reader;
import dnf_writer;

int main()
{
	auto dnf = read_dnf("input.txt");

	while (dnf.try_min_to_tdnf()) {}

	dnf.min_to_mdnf();

	write_dnf(dnf, "output.txt");
}