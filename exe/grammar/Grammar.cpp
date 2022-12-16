#include "Grammar.hpp"

namespace exe::grammar {
    CFGrammar::CFGrammar(const std::vector<char> &alphabet) : alphabet_(alphabet) {}
    CFGrammar::CFGrammar(const CFGrammar &grammar) : rules_(grammar.rules_), alphabet_(grammar.alphabet_),
                                          startNonNeterminal_(grammar.startNonNeterminal_) {}

    void CFGrammar::SetStartNonTerminal(char c) {
        startNonNeterminal_ = c;
    }
    void CFGrammar::SetNonTerminalRules(const std::unordered_map<char, std::vector<exe::grammar::Rule>> &rules) {
        rules_ = rules;
    }

    void CFGrammar::AddNonTerminal(char A, const std::vector<exe::grammar::Rule> &rules) {
        rules_[A] = rules;
    }

    char CFGrammar::GetStartNonNeterminal() const {
        return startNonNeterminal_;
    }
    const std::unordered_map<char, std::vector<exe::grammar::Rule>>& CFGrammar::GetRules() const {
        return rules_;
    }
}
