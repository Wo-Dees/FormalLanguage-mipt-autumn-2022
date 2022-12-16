#include <iostream>

#include "exe/algorithms/Early/Early.hpp"

int main() {
    exe::grammar::CFGrammar grammar;

    grammar.SetStartNonTerminal('S');

    grammar.AddNonTerminal('S', {exe::grammar::CFRule('S', "T+S"), exe::grammar::CFRule('S', "T")});
    grammar.AddNonTerminal('T', {exe::grammar::CFRule('T', "F*T"), exe::grammar::CFRule('T', "F")});
    grammar.AddNonTerminal('F', {exe::grammar::CFRule('F', "(S)"), exe::grammar::CFRule('F', "a")});

    std::string word("(a+a)");

    std::cout << exe::algorithms::Earley(grammar, word);

    return 0;
}
