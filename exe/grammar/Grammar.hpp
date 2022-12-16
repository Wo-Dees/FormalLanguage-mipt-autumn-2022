#pragma once

#include <string>

#include <set>
#include <vector>
#include <unordered_map>

#include "Rule.hpp"

#include "../algorithms/Early/HelperEarly.hpp"

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
        friend exe::algorithms::Situation;
        friend exe::algorithms::EarleyHelper;

        CFGrammar() = default;
        CFGrammar(const std::vector<char>& alphabet);
        CFGrammar(const CFGrammar& grammar);

        void SetStartNonTerminal(char c);
        void SetNonTerminalRules(const std::unordered_map<char, std::vector<exe::grammar::Rule>>& rules);

        void AddNonTerminal(char A, const std::vector<exe::grammar::Rule>& rules);

        char GetStartNonNeterminal() const;
        const std::unordered_map<char, std::vector<exe::grammar::Rule>>& GetRules() const;
    private:
        std::unordered_map<char, std::vector<exe::grammar::Rule>> rules_;
        const std::vector<char> alphabet_{std::vector<char>{'a', 'b', 'c'}};
        char startNonNeterminal_;
    };
} // namespace exe::grammar

