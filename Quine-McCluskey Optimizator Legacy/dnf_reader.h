#pragma once
#include "dnf.h"
#include "logic_value.h"
#include <string>
#include <map>
#include <fstream>

std::string read_line(std::string file_path, unsigned int line_number);
std::vector<logic_value> parse(std::string value);
dnf get_dnf(std::vector<logic_value> function);
dnf read_dnf(std::string file_path);