#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "../Quine-McCluskey Optimization Library Legacy/dnf.h"

namespace qmcc = quine_mc_cluskey;

std::string read_line(std::string file_path, unsigned int line_number);
std::vector<qmcc::logic_value> parse(std::string value);
qmcc::dnf get_dnf(std::vector<qmcc::logic_value> function);
qmcc::dnf read_dnf(std::string file_path);

