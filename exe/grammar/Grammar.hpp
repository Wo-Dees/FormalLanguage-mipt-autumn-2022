#pragma once

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "Rule.hpp"

namespace exe::grammar {
class CFGrammar {
  // Grammar by definition is G = <N, A, S, P>, where:
  //
  // N - set of non-terminals
  // A - alphabet
  // S - start non-terminal
  // P - set of rules
  //
  // My code consist expression for:
  // alphabet - is vector of char,
  // start non-terminal - is char
  // set of non-terminals -> Rules, which corresponds correct left part
 public:
  CFGrammar() = default;
  explicit CFGrammar(const std::vector<char>& alphabet);
  CFGrammar(const CFGrammar& grammar) = default;

  void SetStartNonTerminal(char c);
  void SetRules(
      const std::unordered_map<char, std::vector<exe::grammar::CFRule>>& rules);

  void AddNonTerminal(char A, const std::vector<exe::grammar::CFRule>& rules);
  void DeleteNonTerminal(char A);

  [[nodiscard]] char GetStartNonNeterminal() const;
  [[nodiscard]] const std::unordered_map<char,
                                         std::vector<exe::grammar::CFRule>>&
  GetRules() const;

 private:
  std::unordered_map<char, std::vector<exe::grammar::CFRule>> rules_;
  const std::vector<char> alphabet_{std::vector<char>{'a', 'b', 'c'}};
  char startNonNeterminal_{'\0'};
};

}  // namespace exe::grammar
