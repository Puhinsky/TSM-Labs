#pragma once
#include <string>
#include <fstream>
#include "../Quine-McCluskey Optimization Library Legacy/dnf.h"

namespace qmcc = quine_mc_cluskey;

void write_dnf(const qmcc::dnf& dnf, std::string file_path);
