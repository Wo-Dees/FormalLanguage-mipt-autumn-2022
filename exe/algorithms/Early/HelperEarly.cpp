#include "HelperEarly.hpp"

namespace exe::algorithms {

    EarleyHelper::EarleyHelper(const std::string& word, const grammar::CFGrammar& grammar,
                 std::vector<std::set<exe::algorithms::Situation>>& D) : word_(word), grammar_(grammar), D_(D) {}

    void EarleyHelper::Scan(size_t j) {
        if (j != 0) {
            for (auto& situation : D_[j-1]) {
                if (word_[j-1] == situation.GetNextSym()) {
                    D_[j].insert(Situation(situation, situation.GetLowDot() + 1));
                }
            }
        }
    }

    std::set<exe::algorithms::Situation> EarleyHelper::Complete(const std::set<exe::algorithms::Situation>& set, size_t j) {
        std::set<exe::algorithms::Situation> set_;
        for (auto& situation : set) {
            if (situation.GetNextSym() == '\0') {
                for (auto& situation_ : D_[situation.GetLowDot()]) {
                    if (situation_.GetNextSym() == situation.GetLeftPart()) {
                        set_.emplace(Situation(situation_, j));
                    }
                }
            }
        }
        return set_;
    }

    std::set<exe::algorithms::Situation> EarleyHelper::Predict(const std::set<exe::algorithms::Situation>& set, size_t j) {
        std::set<exe::algorithms::Situation> set_;
        for (auto& situation : set) {
            if ((situation.GetNextSym() <= 'Z' and 'A' <= situation.GetNextSym()) or situation.GetNextSym() == '$') {
                for (auto& rule : grammar_.GetRules().find(situation.GetNextSym())->second) {
                    set_.emplace(Situation(rule, 0, j));
                }
            }
        }
        return set_;
    }

    void EarleyHelper::Relax(size_t j) {
        std::set<exe::algorithms::Situation> set(D_[j]);
        while (!set.empty()) {
            std::set<exe::algorithms::Situation> set1(exe::algorithms::EarleyHelper::Complete(set,  j));
            std::set<exe::algorithms::Situation> set2(exe::algorithms::EarleyHelper::Predict(set, j));
            set1.merge(set2);
            D_[j].merge(set);
            set = std::move(set1);
        }
    }

} // namespace exe::algorithms