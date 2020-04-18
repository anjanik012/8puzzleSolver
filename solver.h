//
// Created by anjani on 10/3/19.
//
// This class implements the A* search algorithm with Tiles out of place Heuristic.

#ifndef INC_8PUZZLE_SOLVER_H
#define INC_8PUZZLE_SOLVER_H

#include "game_state.h"
#include <forward_list>
#include <unordered_set>

class solver {
private:
    game_state current_state;
    std::forward_list<char> solution;
    uint32_t nodes_explored;
    uint32_t total_moves;
public:
    explicit solver(const game_state &current_state);
    void solve();
    const std::forward_list<char> &get_solution() const;

    uint32_t get_nodes_explored() const;

    uint32_t get_total_moves() const;

};

#endif //INC_8PUZZLE_SOLVER_H
