#pragma once

#include <unordered_set>
#include "minterm.h"

typedef std::unordered_set<minterm, minterm::hash> minterms_set;