#include <gtest/gtest.h>

#include "../exe/algorithms/Early/Early.hpp"

TEST(Earley, Grammar1) {
  exe::grammar::CFGrammar grammar2;

  grammar2.SetStartNonTerminal('S');

  grammar2.AddNonTerminal(
      'S', {exe::grammar::CFRule('S', ""), exe::grammar::CFRule('S', "(S)"),
            exe::grammar::CFRule('S', "SS")});

  std::string word5("()");
  std::string word6("(())");
  std::string word7("(()");
  std::string word8("(ddvdf");

  EXPECT_TRUE(exe::algorithms::Earley(grammar2, word5));
  EXPECT_TRUE(exe::algorithms::Earley(grammar2, word6));
  EXPECT_TRUE(!exe::algorithms::Earley(grammar2, word7));
  EXPECT_TRUE(!exe::algorithms::Earley(grammar2, word8));
}

TEST(Earley, Grammar2) {
  exe::grammar::CFGrammar grammar1;

  grammar1.SetStartNonTerminal('S');

  grammar1.AddNonTerminal(
      'S', {exe::grammar::CFRule('S', "T+S"), exe::grammar::CFRule('S', "T")});
  grammar1.AddNonTerminal(
      'T', {exe::grammar::CFRule('T', "F*T"), exe::grammar::CFRule('T', "F")});
  grammar1.AddNonTerminal(
      'F', {exe::grammar::CFRule('F', "(S)"), exe::grammar::CFRule('F', "a")});

  std::string word1("(a+a)");
  std::string word2("a*a+a");
  std::string word3("(a+a+a+a)");
  std::string word4("(a+a+a+a");

  EXPECT_TRUE(exe::algorithms::Earley(grammar1, word1));
  EXPECT_TRUE(exe::algorithms::Earley(grammar1, word2));
  EXPECT_TRUE(exe::algorithms::Earley(grammar1, word3));
  EXPECT_TRUE(!exe::algorithms::Earley(grammar1, word4));
}

TEST(Earley, Grammar3) {
  exe::grammar::CFGrammar grammar3;

  grammar3.SetStartNonTerminal('S');

  grammar3.AddNonTerminal('S', {
                                   exe::grammar::CFRule('S', ""),
                                   exe::grammar::CFRule('S', "a"),
                                   exe::grammar::CFRule('S', "b"),
                                   exe::grammar::CFRule('S', "aSa"),
                                   exe::grammar::CFRule('S', "bSb"),
                               });

  std::string word1("aba");
  std::string word2("aabbbbbbaa");
  std::string word3("aaabb");
  std::string word4("aabaaa");

  EXPECT_TRUE(exe::algorithms::Earley(grammar3, word1));
  EXPECT_TRUE(exe::algorithms::Earley(grammar3, word2));
  EXPECT_TRUE(!exe::algorithms::Earley(grammar3, word3));
  EXPECT_TRUE(!exe::algorithms::Earley(grammar3, word4));
}

TEST(Earley, Grammar4) {
    exe::grammar::CFGrammar grammar4;

    grammar4.SetStartNonTerminal('R');

    grammar4.AddNonTerminal('R', {
            exe::grammar::CFRule('R', "XRX"),
            exe::grammar::CFRule('R', "S"),
    });
    grammar4.AddNonTerminal('S', {
            exe::grammar::CFRule('S', "aTb"),
            exe::grammar::CFRule('S', "bTa"),
    });
    grammar4.AddNonTerminal('T', {
            exe::grammar::CFRule('T', "XTX"),
            exe::grammar::CFRule('T', "X"),
            exe::grammar::CFRule('T', "")
    });
    grammar4.AddNonTerminal('X', {
            exe::grammar::CFRule('X', "b"),
            exe::grammar::CFRule('X', "a")
    });

    std::string word1("aba");
    std::string word2("aabbbbbbaa");
    std::string word3("aaabb");
    std::string word4("aabaaa");

    EXPECT_TRUE(!exe::algorithms::Earley(grammar4, word1));
    EXPECT_TRUE(!exe::algorithms::Earley(grammar4, word2));
    EXPECT_TRUE(exe::algorithms::Earley(grammar4, word3));
    EXPECT_TRUE(exe::algorithms::Earley(grammar4, word4));
}

TEST(Earley, Grammar5) {
    exe::grammar::CFGrammar grammar5;

    grammar5.SetStartNonTerminal('S');

    grammar5.AddNonTerminal(
            'S', {exe::grammar::CFRule('S', ""), exe::grammar::CFRule('S', "(S)"),
                  exe::grammar::CFRule('S', "SS")});
    grammar5.AddNonTerminal('R', {
            exe::grammar::CFRule('R', "XRX"),
            exe::grammar::CFRule('R', "S"),
    });
    grammar5.AddNonTerminal('T', {
            exe::grammar::CFRule('T', "XTX"),
            exe::grammar::CFRule('T', "X"),
            exe::grammar::CFRule('T', "")
    });
    grammar5.AddNonTerminal('X', {
            exe::grammar::CFRule('X', "b"),
            exe::grammar::CFRule('X', "a")
    });

    std::string word5("()");
    std::string word6("(())");
    std::string word7("(()");
    std::string word8("(ddvdf");

    EXPECT_TRUE(exe::algorithms::Earley(grammar5, word5));
    EXPECT_TRUE(exe::algorithms::Earley(grammar5, word6));
    EXPECT_TRUE(!exe::algorithms::Earley(grammar5, word7));
    EXPECT_TRUE(!exe::algorithms::Earley(grammar5, word8));
}
