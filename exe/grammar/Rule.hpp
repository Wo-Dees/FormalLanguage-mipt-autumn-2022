#pragma once

#include <string>

namespace exe::grammar {
    class Rule {
        // Rule in CF grammar by definition is pair
        // Non-terminal -> alpha in (A u N)*
        // My abstractions is:
        // Non-terminal is char
        // alpha is std::string
    public:
        Rule() = delete;
        Rule(char leftPart, const std::string &rightPart);
        Rule(const Rule &rule);

        const char &GetLeftPart() const;
        const std::string &GetRightPart() const;

        Rule& operator=(const Rule& rule);
    private:
        char leftPart_;
        std::string rightPart_;
    };
} // namespace exe::grammar
