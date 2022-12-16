#include "Situation.hpp"

namespace exe::algorithms {
    Situation::Situation(const exe::grammar::Rule& rule, size_t index_low_dot, size_t index_high_dot) :
    rule_(rule), index_low_dot_(index_low_dot), index_high_dot_(index_high_dot) {}

    Situation::Situation(const Situation& situation, size_t index_low_dot) :
    rule_(situation.rule_), index_low_dot_(index_low_dot), index_high_dot_(situation.index_high_dot_) {}

    bool Situation::operator<(const Situation& situation) const {
        return true;
    }
    bool Situation::operator==(const Situation& situation) const {
        return true;
    }

    size_t Situation::GetLowDot() const {
        return index_low_dot_;
    }
    size_t Situation::GetHighDot() const {
        return index_high_dot_;
    }
    char Situation::GetNextSym() const {
        return rule_.GetRightPart()[index_low_dot_];
    }
    char Situation::GetLeftPart() const {
        return rule_.GetLeftPart();
    }
} // namespace exe::algorithms