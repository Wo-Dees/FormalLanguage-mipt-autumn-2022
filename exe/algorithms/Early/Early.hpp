#pragma once

#include <string>

#include "HelperEarly.hpp"

namespace exe::algorithms {

    bool Earley(const grammar::CFGrammar& grammar, const std::string& word);

} // namespace exe::algorithms
