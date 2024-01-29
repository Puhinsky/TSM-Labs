#pragma once
#include <ostream>
#include <vector>
#include <map>
#include <fstream>

void print(std::ostream& os, std::vector<int> result, std::map<std::string, unsigned int> id_map);

void save(std::string file_path, std::vector<int> result, std::map<std::string, unsigned int> id_map);

