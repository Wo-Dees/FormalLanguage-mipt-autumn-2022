#pragma once

#include "NonDeterministicAutomaton.h"

#include <iostream>
#include <list>
#include <queue>
#include <string>

namespace exe::automaton {

NonDeterministicAutomaton::NonDeterministicAutomaton(size_t n, size_t initial)
    : states_(n), initial_(initial) {}

void NonDeterministicAutomaton::AddVertex(size_t from, size_t to,
                                          const std::string &word) {
  states_[from].linklist_.emplace_back(Link(to, word));
}

void NonDeterministicAutomaton::SetDeterministic(size_t state) {
  deterministic_.push_back(state);
  states_[state].deterministic_ = true;
}

void NonDeterministicAutomaton::DeleteWordLink() {
  //    size_t initial_states = states_.size();
  //    for (size_t index_state = 0; index_state < initial_states;
  //    ++index_state) {
  //        RelaxState(index_state);
  //    }
}

void NonDeterministicAutomaton::DeleteELink() {
  SetDeterministicState();
  // HandleState();
}

void NonDeterministicAutomaton::SetDeterministicState() {
  std::vector<bool> visited(states_.size(), false);
  std::queue<size_t> q;
  auto end_state = deterministic_.end();
  for (auto state = deterministic_.begin(); state != end_state; ++state) {
    if (!visited[*state]) {
      q.push(*state);
    }
    while (!q.empty()) {
      size_t v = q.front();
      q.pop();
      visited[v] = true;
      for (auto &link : states_[v].linklist_) {
        if (link.word_ == "" and states_[v].deterministic_ and
            !visited[link.state_]) {
          states_[link.state_].deterministic_ = true;
          deterministic_.push_back(link.state_);
          q.push(link.state_);
        }
      }
    }
  }
}

void NonDeterministicAutomaton::HandleState() {
  for (size_t i = 0; i < states_.size(); ++i) {
    std::queue<size_t> q;
    q.push(i);
    size_t count_while = 0;
    while (!q.empty()) {
      ++count_while;
      size_t v = q.front();
      q.pop();
      for (auto link = states_[v].linklist_.begin();
           link != states_[v].linklist_.end(); ++link) {
        if (link->word_ == "" and link->state_ != v) {
          states_[v].linklist_.erase(link);
          if (link->state_ != v) {
            q.push(link->state_);
          }
        }
        if (count_while > 1 and link->word_ != "") {
          states_[v].linklist_.emplace_back(Link(link->state_, link->word_));
        }
      }
    }
  }
}

void NonDeterministicAutomaton::RelaxState(size_t state) {
  for (auto link = states_[state].linklist_.begin();
       link != states_[state].linklist_.end(); ++link) {
    if (link->word_.size() > 1) {
      RelaxWordState(state, *link);
      states_[state].linklist_.erase(link);
    }
  }
}

void NonDeterministicAutomaton::RelaxWordState(
    size_t state, const NonDeterministicAutomaton::Link &link) {
  //    for (size_t i = 0; i < link.word_.size(); ++i) {
  //        states_.emplace_back(State());
  //        states_[states_.size() - 1].linklist_.emplace_back(
  //                Link(link.state_, link.word_[link.word_.size() - i - 1])
  //        );
  //    }
}

void NonDeterministicAutomaton::PrintAutomation() {
  std::cout << "initial state: " << initial_ << std::endl;
  for (auto &state : states_) {
    std::cout << "===================================" << std::endl;
    std::cout << state.deterministic_ << std::endl;
    for (auto &link : state.linklist_) {
      std::cout << link.state_ << " " << link.word_ << std::endl;
    }
    std::cout << "===================================" << std::endl;
  }
}

}  // namespace exe::automaton
