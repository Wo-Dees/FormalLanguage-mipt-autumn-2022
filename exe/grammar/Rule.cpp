#include "Rule.hpp"

namespace exe::grammar {
    CFRule::CFRule(char leftPart, const std::string &rightPart) : leftPart_(leftPart), rightPart_(rightPart) {}
    CFRule::CFRule(char leftPart, char rightPart) : leftPart_(leftPart), rightPart_(1, rightPart) {}
    CFRule::CFRule(const CFRule &rule) : leftPart_(rule.leftPart_), rightPart_(rule.rightPart_) {}

    const char& CFRule::GetLeftPart() const  {
        return leftPart_;
    }
    const std::string& CFRule::GetRightPart() const {
        return rightPart_;
    }

    CFRule& CFRule::operator=(const exe::grammar::CFRule &rule) {
        leftPart_ = rule.leftPart_;
        rightPart_ = rule.rightPart_;
        return *this;
    }

    bool CFRule::operator==(const exe::grammar::CFRule &rule) const {
        return leftPart_ == rule.leftPart_ and rightPart_ == rule.rightPart_;
    }
} // namespace exe::grammar