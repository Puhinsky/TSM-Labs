export module minterms_set;

import <unordered_set>;
import minterm;

export typedef std::unordered_set<minterm, minterm::hash> minterms_set;