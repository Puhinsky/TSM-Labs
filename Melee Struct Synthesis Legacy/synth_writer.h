#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../Quine-McCluskey Optimizator Legacy/dnf.h"

void write_synth_to_file(std::vector<dnf> triggers, std::vector<dnf> outs, std::string file_path);
void write_synth_to_console(std::vector<dnf> triggers, std::vector<dnf> outs);
void write_dnfs_set(std::vector<dnf> dnfs, std::string prefix, std::ostream& os);

