#pragma once

#include <string>
#include <vector>
#include <set>

#include "Situation.hpp"
#include "../../grammar/Grammar.hpp"

namespace exe::algorithms {
    class EarleyHelper {
    public:
        EarleyHelper(const std::string& word, const grammar::CFGrammar& grammar,
                     std::vector<std::set<exe::algorithms::Situation>>& D);
        void Scan(size_t j);
        void Relax(size_t j);
    private:

        std::set<exe::algorithms::Situation> Complete(const std::set<exe::algorithms::Situation>& set, size_t j);
        std::set<exe::algorithms::Situation> Predict(const std::set<exe::algorithms::Situation>& set, size_t j);

        const std::string& word_;
        const grammar::CFGrammar& grammar_;
        std::vector<std::set<exe::algorithms::Situation>>& D_;
    };
} // namespace exe::algorithms


