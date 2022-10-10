//
// Created by Леонид Переверзин on 07.10.2022.
//

#ifndef AUTOMATIONS_DETERMINISTICAUTOMATION_H
#define AUTOMATIONS_DETERMINISTICAUTOMATION_H

#include "NonDeterministicAutomaton.h"

#include <map>
#include <deque>
#include <vector>
#include <bitset>

class DeterministicAutomation {
public:

    explicit DeterministicAutomation(const NonDeterministicAutomaton& automation) {
        size_t state = 0;
        std::map<size_t, std::pair<bool, size_t>> visited;
        std::queue<std::bitset<128>> q;
        std::bitset<128> initial;
        initial[automation.initial_] = true;
        while (!q.empty()) {
            std::bitset<128> new_state = q.front();
            q.pop();
            if (visited.find(new_state.to_ullong()) != visited.end()) {
                states_.emplace_back(State());
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                std::bitset<128> new_new_state;
                for (size_t i = 0; i < new_state.size(); ++i) {
                    if (new_state[i]) {

                    }
                }
            }
            ++state;
        }
    }

    DeterministicAutomation(size_t states, size_t initial) : states_(states), initial_(initial) {

    }
    void AddLink(size_t from, size_t to, char c) {

    }
    void BuildFullDeterministicAutomation() {

    }
    void AdditionalToAutomation() {

    }
private:

    struct State {
        State() = default;
        std::vector<size_t> links_;
        bool deterministic{false};
    };

private:

    std::deque<State> states_;
    size_t initial_;

};


#endif //AUTOMATIONS_DETERMINISTICAUTOMATION_H
