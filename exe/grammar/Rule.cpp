#include "Rule.hpp"

namespace exe::grammar {
    Rule::Rule(char leftPart, const std::string &rightPart) : leftPart_(leftPart), rightPart_(rightPart) {}
    Rule::Rule(const Rule &rule) : leftPart_(rule.leftPart_), rightPart_(rule.rightPart_) {}

    const char& Rule::GetLeftPart() const  {
        return leftPart_;
    }
    const std::string& Rule::GetRightPart() const {
        return rightPart_;
    }

    Rule& Rule::operator=(const exe::grammar::Rule &rule) {
        leftPart_ = rule.leftPart_;
        rightPart_ = rule.rightPart_;
    }
} // namespace exe::grammar