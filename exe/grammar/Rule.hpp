#pragma once

#include <string>

namespace exe::grammar {
class CFRule {
  // Rule in CF grammar by definition is pair
  // Non-terminal -> alpha in (A u N)*
  // My abstractions is:
  // Non-terminal is char
  // alpha is std::string
 public:
  CFRule() = delete;

  CFRule(char leftPart, const std::string &rightPart);
  CFRule(char leftPart, char rightPart);
  CFRule(const CFRule &rule);

  const char &GetLeftPart() const;
  const std::string &GetRightPart() const;

  bool operator==(const CFRule &rule) const;

  CFRule &operator=(const CFRule &rule);

 private:
  char leftPart_;
  std::string rightPart_;
};
}  // namespace exe::grammar
