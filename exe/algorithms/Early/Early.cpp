#include "HelperEarly.hpp"
#include "Situation.hpp"

#include <iostream>
#include <vector>
#include <set>

namespace exe::algorithms {
    bool Earley(const grammar::CFGrammar& grammar, const std::string& word) {
        std::vector<std::set<exe::algorithms::Situation>> D(word.size() + 1);
        exe::algorithms::EarleyHelper helper(word, grammar, D);
        D[0].insert(exe::algorithms::Situation(exe::grammar::CFRule(
                '$', std::string(1, grammar.GetStartNonNeterminal())),
                                               0, 0)); // bedug parametr 0
        for (size_t j = 0; j < word.size() + 1; ++j) {
            helper.Scan(j);
            helper.Relax(j);
        }

        // DEBUG CODE
//        for (size_t i = 0; i < word.size(); ++i) {
//            std::cout << "-----------------------------" << i << std::endl;
//            for (auto& el : D[i]) {
//                std::cout << el.GetLeftPart() << " " << el.GetRightPart() << " " << el.GetLowDot() << " " << el.GetHighDot() << " " << el.GetWho() << std::endl;
//            }
//            std::cout << "-----------------------------" << std::endl;
//        }
        // DEBUG
        return D[word.size()].contains(
                exe::algorithms::Situation(exe::grammar::CFRule(
                        '$', std::string(1, grammar.GetStartNonNeterminal())),
                                           1,0)); // bedug parametr 0
    }
} // namespace exe::algorithms