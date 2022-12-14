#include "HelperEarly.hpp"

#include <iostream>

namespace exe::algorithms {

EarleyHelper::EarleyHelper(const std::string& word,
                           const exe::grammar::CFGrammar& grammar,
                           std::vector<std::set<exe::algorithms::Situation>>& D)
    : word_(word), grammar_(grammar), D_(D) {}

void EarleyHelper::Scan(size_t j) {
  if (j != 0) {
    for (auto& situation : D_[j - 1]) {
      if (word_[j - 1] == situation.GetNextSym()) {
        D_[j].insert(Situation(
            situation, situation.GetLowDot() + 1));  // bedug parametr 11
      }
    }
  }
}

std::set<exe::algorithms::Situation> EarleyHelper::Complete(
    const std::set<exe::algorithms::Situation>& set /*, size_t j */) {
  std::set<exe::algorithms::Situation> set_;
  for (auto& situation : set) {
    if (situation.GetNextSym() == '\0') {
      for (auto& situation_ : D_[situation.GetHighDot()]) {
        if (situation_.GetNextSym() == situation.GetLeftPart()) {
          set_.emplace(
              Situation(situation_, situation_.GetLowDot() + 1,
                        situation_.GetHighDot()));  // bedug parametr 33
        }
      }
    }
  }
  return set_;
}

std::set<exe::algorithms::Situation> EarleyHelper::Predict(
    const std::set<exe::algorithms::Situation>& set, size_t j) {
  std::set<exe::algorithms::Situation> set_;
  for (auto& situation : set) {
    if (situation.GetNextSym() <= 'Z' and 'A' <= situation.GetNextSym()) {
      for (auto& rule :
           grammar_.GetRules().find(situation.GetNextSym())->second) {
        set_.emplace(Situation(rule, 0, j));  // bedug parametr 55
      }
    }
  }
  return set_;
}

void EarleyHelper::Relax(size_t j) {
  std::set<exe::algorithms::Situation> set(D_[j]);
  size_t lastDj = 0, Dj = D_[j].size();
  size_t index = 0;
  while ((!set.empty() and lastDj != Dj) or index == 1) {
    std::set<exe::algorithms::Situation> set1(
        exe::algorithms::EarleyHelper::Complete(set /*,  j*/));
    std::set<exe::algorithms::Situation> set2(
        exe::algorithms::EarleyHelper::Predict(set, j));
    set1.merge(set2);
    D_[j].merge(set);
    set = std::move(set1);
    lastDj = Dj;
    Dj = D_[j].size();
    ++index;
  }
}

}  // namespace exe::algorithms