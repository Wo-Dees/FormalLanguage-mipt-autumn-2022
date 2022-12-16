#include "Situation.hpp"

namespace exe::algorithms {
    Situation::Situation(const exe::grammar::CFRule& rule, size_t index_low_dot, size_t index_high_dot) :
    rule_(rule), index_high_dot_(index_high_dot), index_low_dot_(index_low_dot) {}

    Situation::Situation(const Situation& situation, size_t index_low_dot) :
    rule_(situation.rule_), index_high_dot_(situation.index_high_dot_), index_low_dot_(index_low_dot) {}

    bool Situation::operator<(const Situation& situation) const {
        if (rule_.GetLeftPart() < situation.GetLeftPart()) {
            return true;
        } else if (rule_.GetLeftPart() == situation.GetLeftPart()) {
            if (index_high_dot_ < situation.index_high_dot_) {
                return true;
            } else if (index_high_dot_ == situation.index_high_dot_) {
                if (index_low_dot_ < situation.index_low_dot_) {
                    return true;
                } else if (index_low_dot_ == situation.index_low_dot_) {
                    if (rule_.GetRightPart() < situation.rule_.GetRightPart()) {
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    bool Situation::operator==(const Situation& situation) const {
        return situation.index_low_dot_ == index_low_dot_ &&
        situation.index_high_dot_ == index_high_dot_ &&
        situation.rule_ == rule_;
    }

    size_t Situation::GetLowDot() const {
        return index_low_dot_;
    }
    size_t Situation::GetHighDot() const {
        return index_high_dot_;
    }
    char Situation::GetNextSym() const {
        if (index_low_dot_ < rule_.GetRightPart().size()) {
            return rule_.GetRightPart()[index_low_dot_];
        }
        return '\0';
    }
    char Situation::GetLeftPart() const {
        return rule_.GetLeftPart();
    }
} // namespace exe::algorithms