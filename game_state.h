//
// Created by anjani on 10/3/19.
// This class is represents a game state.
// These states are modified in order to find the solution.
//

#ifndef INC_8PUZZLE_GAME_STATE_H
#define INC_8PUZZLE_GAME_STATE_H

#include <array>

using std::array;
using std::pair;

class game_state {
private:
    array<array<int, 3>, 3> grid{};
    const array<array<int, 3>, 3> goal = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}};
    pair<int, int> zero_position;
    int n_tiles_out_of_place;
    int n_moves;
    char last_move;
    game_state *prev_state;
public:
    game_state();

    explicit game_state(const std::string &);

    game_state(const game_state &);

    game_state(const game_state &, game_state *);

    array<array<int, 3>, 3> get_current_grid() const;

    array<array<int, 3>, 3> get_goal_grid() const;

    pair<int, int> get_zero_position() const;

    int get_n_tiles_out_of_place() const;

    int get_n_moves() const;

    game_state *get_prev_state() const;

    int get_heuristic() const;

    bool is_goal_state();

    bool move_up();

    bool move_down();

    bool move_left();

    bool move_right();

    char get_last_move() const;

    bool operator==(const game_state &rhs) const;

    bool operator!=(const game_state &rhs) const;

    bool operator<(const game_state &rhs) const;

    game_state &operator=(const game_state &);


};

// Object hash
namespace std {
    template<>
    struct hash<game_state> {
        size_t operator()(const game_state &state) const {
            std::string val;
            auto grid = state.get_current_grid();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int x = grid[i][j] + 48;
                    val += x;
                }
            }
            return std::hash<std::string>()(val);
        }
    };
}

#endif
