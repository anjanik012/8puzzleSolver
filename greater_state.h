//
// Created by anjani on 10/4/19.
//

/*
 * This class implements the greater than operator for game_state class.
 */

#ifndef INC_8PUZZLE_GREATER_STATE_H
#define INC_8PUZZLE_GREATER_STATE_H

#include "game_state.h"

class greater_state{
public:
    bool operator()(game_state const &g1, game_state const &g2) {
        return g1.get_n_tiles_out_of_place() > g2.get_n_tiles_out_of_place();
    }
};

#endif //INC_8PUZZLE_GREATER_STATE_H
