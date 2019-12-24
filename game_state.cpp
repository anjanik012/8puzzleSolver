//
// Created by anjani on 10/3/19.
//

// Implementation of class game_state.

#include "game_state.h"

/*
 * Constructors including obsolete default constructor.
 */

game_state::game_state() {
    zero_position.first = zero_position.second = -1;
    n_tiles_out_of_place = -1;
    n_moves = -1;
    last_move = '\0';
    prev_state = nullptr;
}

game_state::game_state(const std::string &input_grid) {
    for (int i = 0; i <= 2; ++i) {
        grid[0][i] = input_grid[i] - 48;
    }
    for (int i = 0; i <= 2; ++i) {
        grid[1][i] = input_grid[i + 3] - 48;
    }
    for (int i = 0; i <= 2; ++i) {
        grid[2][i] = input_grid[i + 6] - 48;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0) {
                zero_position.first = i;
                zero_position.second = j;
            }
        }
    }
    n_tiles_out_of_place = 0;
    n_moves = 0;
    last_move = '\0';
    prev_state = nullptr;
    set_n_tiles();
}

game_state::game_state(const game_state &state) {
    grid = state.grid;
    zero_position = state.zero_position;
    n_tiles_out_of_place = state.n_tiles_out_of_place;
    last_move = state.last_move;
    n_moves = state.n_moves;
    prev_state = state.prev_state;
}

game_state::game_state(const game_state &state, game_state *prev) : prev_state(prev) {
    grid = state.grid;
    zero_position = state.zero_position;
    n_tiles_out_of_place = state.n_tiles_out_of_place;
    last_move = state.last_move;
    n_moves = state.n_moves;
}

/*
 * Member Functions.
 */

bool game_state::is_goal_state() {
//    return grid[0][0] == goal[0][0] && grid[0][1] == goal[0][1] && grid[0][2] == goal[0][2] &&
//           grid[1][0] == goal[1][0] && grid[1][1] == goal[1][1] && grid[1][2] == goal[1][2] &&
//           grid[2][0] == goal[2][0] && grid[2][1] == goal[2][1] && grid[2][2] == goal[2][2];
    return n_tiles_out_of_place == 0;
}

std::pair<int, int> game_state::get_zero_position() const {
    return zero_position;
}

array<array<int, 3>, 3> game_state::get_goal_grid() const {
    return goal;
}

array<array<int, 3>, 3> game_state::get_current_grid() const {
    return grid;
}

bool game_state::move_up() {
    int i = zero_position.first;
    int j = zero_position.second;
    if (grid[i - 1][j] == goal[i - 1][j]) {
        n_tiles_out_of_place++;
    }
    if (i != 0) {
        swap(grid[i][j], grid[i - 1][j]);
        zero_position.first = i - 1;
//        set_n_tiles();
        if (grid[i][j] == goal[i][j]) {
            n_tiles_out_of_place--;
        }
        n_moves++;
        last_move = 'U';
        return true;
    }
    return false;
}

bool game_state::move_down() {
    int i = zero_position.first;
    int j = zero_position.second;
    if (grid[i + 1][j] == goal[i + 1][j]) {
        n_tiles_out_of_place++;
    }
    if (i != 2) {
        swap(grid[i][j], grid[i + 1][j]);
        zero_position.first = i + 1;
//        set_n_tiles();
        if (grid[i][j] == goal[i][j]) {
            n_tiles_out_of_place--;
        }
        n_moves++;
        last_move = 'D';
        return true;
    }
    return false;
}

bool game_state::move_left() {
    int i = zero_position.first;
    int j = zero_position.second;
    if (grid[i][j - 1] == goal[i][j - 1]) {
        n_tiles_out_of_place++;
    }
    if (j != 0) {
        swap(grid[i][j], grid[i][j - 1]);
        zero_position.second = j - 1;
//        set_n_tiles();
        if (grid[i][j] == goal[i][j]) {
            n_tiles_out_of_place--;
        }
        n_moves++;
        last_move = 'L';
        return true;
    }
    return false;
}

bool game_state::move_right() {
    int i = zero_position.first;
    int j = zero_position.second;
    if (grid[i][j + 1] == goal[i][j + 1]) {
        n_tiles_out_of_place++;
    }
    if (j != 2) {
        swap(grid[i][j], grid[i][j + 1]);
        zero_position.second = j + 1;
//        set_n_tiles();
        if (grid[i][j] == goal[i][j]) {
            n_tiles_out_of_place--;
        }
        n_moves++;
        last_move = 'R';
        return true;
    }
    return false;
}

int game_state::get_n_tiles_out_of_place() const {
    return n_tiles_out_of_place;
}

int game_state::get_n_moves() const {
    return n_moves;
}

int game_state::get_heuristic() const {
    return n_moves + n_tiles_out_of_place;
}

char game_state::get_last_move() const {
    return last_move;
}

game_state *game_state::get_prev_state() const {
    return prev_state;
}

/*
 * Operators.
 */

bool game_state::operator<(const game_state &rhs) const {
    return n_tiles_out_of_place < rhs.n_tiles_out_of_place;
}

game_state &game_state::operator=(const game_state &rhs) {
    if (this == &rhs) {
        return *this;
    }
    grid = rhs.grid;
    zero_position = rhs.zero_position;
    n_tiles_out_of_place = rhs.n_tiles_out_of_place;
    last_move = rhs.last_move;
    n_moves = rhs.n_moves;
    prev_state = rhs.prev_state;
    return *this;
}








