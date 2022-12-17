#include "Grammar.hpp"

namespace exe::grammar {
CFGrammar::CFGrammar(const std::vector<char> &alphabet) : alphabet_(alphabet) {}

void CFGrammar::SetStartNonTerminal(char c) { startNonNeterminal_ = c; }
void CFGrammar::SetRules(
    const std::unordered_map<char, std::vector<exe::grammar::CFRule>> &rules) {
  rules_ = rules;
}

void CFGrammar::AddNonTerminal(char A,
                               const std::vector<exe::grammar::CFRule> &rules) {
  if (rules_.find(A) == rules_.end()) {
    rules_[A] = rules;
    return;
  }
  copy(rules.begin(), rules.end(), rules_[A].begin());
}
void CFGrammar::DeleteNonTerminal(char A) { rules_.erase(A); }

char CFGrammar::GetStartNonNeterminal() const { return startNonNeterminal_; }
const std::unordered_map<char, std::vector<exe::grammar::CFRule>>
    &CFGrammar::GetRules() const {
  return rules_;
}
}  // namespace exe::grammar
