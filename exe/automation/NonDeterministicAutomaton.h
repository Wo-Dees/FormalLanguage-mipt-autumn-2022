#pragma once

namespace exe::automaton {

class DeterministicAutomation;

class NonDeterministicAutomaton {
 public:
  NonDeterministicAutomaton(size_t n, size_t initial);

  void AddVertex(size_t from, size_t to, const std::string &word);

  void SetDeterministic(size_t state);

  void DeleteWordLink();

  void DeleteELink();

  void PrintAutomation();

 private:
  struct Link {
    Link(size_t state, const std::string &word) : state_(state), word_(word) {}

    size_t state_;
    std::string word_;
  };

  struct State {
    State() : deterministic_(false) {}

    std::list<Link> linklist_;
    bool deterministic_;
  };

 private:
  void SetDeterministicState();

  void HandleState();

  void RelaxState(size_t state);

  void RelaxWordState(size_t state, const Link &link);

 private:
  friend DeterministicAutomation;

 private:
  std::deque<State> states_;
  std::list<size_t> deterministic_;
  size_t initial_;
};

}  // namespace exe::automaton
