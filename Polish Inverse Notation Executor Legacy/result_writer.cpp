#include "result_writer.h"

using namespace::std;

void print(std::ostream& os, std::vector<int> result, std::map<std::string, unsigned int> id_map)
{
	map<string, unsigned int> ::iterator it;

	for (auto i = 0; i < result.size(); ++i)
	{
		it = id_map.begin();

		while (it->second != i)
			it++;

		os << it->first << " = " << result[i] << endl;
	}
}

void save(std::string file_path, std::vector<int> result, std::map<std::string, unsigned int> id_map)
{
	ofstream os(file_path);
	print(os, result, id_map);
	os.close();
}
