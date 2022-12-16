#pragma once

#include "../../grammar/Rule.hpp"

namespace exe::algorithms {
    class Situation {
    public:
        Situation(const exe::grammar::CFRule& rule, size_t index_low_dot_, size_t index_high_dot_);
        Situation(const Situation& situation, size_t index_low_dot_);
        Situation(const Situation& situation, size_t index_low_dot_, size_t index_high_dot_);

        bool operator<(const Situation& situation) const;
        bool operator==(const Situation& situation) const;

        [[nodiscard]] size_t GetLowDot() const;
        [[nodiscard]] size_t GetHighDot() const;
        [[nodiscard]] char GetNextSym() const;
        [[nodiscard]] char GetLeftPart() const;
    private:
        exe::grammar::CFRule rule_;
        size_t index_high_dot_{0};
        size_t index_low_dot_{0};

    };
} // namespace exe::algorithms
