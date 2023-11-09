#pragma once

#include <unordered_set>
#include "minterm.h"

namespace quine_mc_cluskey
{
	typedef std::unordered_set<minterm, minterm::hash> minterms_set;
}