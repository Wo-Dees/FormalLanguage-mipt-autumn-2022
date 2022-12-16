#include "HelperEarly.hpp"
#include "Situation.hpp"

#include <vector>
#include <set>

namespace exe::algorithms {
    bool Earley(const grammar::CFGrammar& grammar, const std::string& word) {
        std::vector<std::set<exe::algorithms::Situation>> D(word.size() + 1);
        exe::algorithms::EarleyHelper helper(word, grammar, D);
        D[0].insert(exe::algorithms::Situation(exe::grammar::CFRule('$', "b"), 0, 0));
        for (size_t j = 0; j < word.size() + 1; ++j) {
            helper.Scan(j);
            helper.Relax(j);
        }
        return D[word.size()].contains(
                exe::algorithms::Situation(exe::grammar::CFRule('$', "b"), 0, word.size())
                );
    }
} // namespace exe::algorithms