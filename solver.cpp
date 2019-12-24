//
// Created by anjani on 10/3/19.
//

/*
 * This class implements the A* search algorithm
 * to find the optimal closed_list for the 8 puzzle game.
 *
 */
#include "solver.h"

#include <queue>
#include <iostream>

using std::priority_queue;
using std::pair;
using std::vector;
using std::forward_list;
using std::greater;
using std::make_pair;
using std::cout;
using std::endl;
using std::move;

solver::solver(const game_state &input_state) : current_state(input_state) {}

void solver::solve() {
    priority_queue<pair<int, game_state>, vector<pair<int, game_state>>, greater<>> p;
    pair<int, game_state> root = make_pair(current_state.get_heuristic(), current_state);
    p.push(root);
    game_state *g_p = nullptr;
    while (!p.empty()) {
        auto u = p.top();
        p.pop();
        g_p = new game_state(u.second);
        if (g_p->is_goal_state()) {
            cout << "Number of moves:" <<g_p->get_n_moves() << endl;
            break;
        }
        vector<game_state> paths(4, game_state(*g_p, g_p));
        switch (g_p->get_last_move()) {
            case 'U':
                if (paths[0].move_up()) {
                    p.push(make_pair(paths[0].get_heuristic(), paths[0]));
                }
                if (paths[1].move_left()) {
                    p.push(make_pair(paths[1].get_heuristic(), paths[1]));
                }
                if (paths[2].move_right()) {
                    p.push(make_pair(paths[2].get_heuristic(), paths[2]));
                }
                break;
            case 'D':
                if (paths[0].move_down()) {
                    p.push(make_pair(paths[0].get_heuristic(), paths[0]));
                }
                if (paths[1].move_left()) {
                    p.push(make_pair(paths[1].get_heuristic(), paths[1]));
                }
                if (paths[2].move_right()) {
                    p.push(make_pair(paths[2].get_heuristic(), paths[2]));
                }
                break;
            case 'L':
                if (paths[0].move_up()) {
                    p.push(make_pair(paths[0].get_heuristic(), paths[0]));
                }
                if (paths[1].move_down()) {
                    p.push(make_pair(paths[1].get_heuristic(), paths[1]));
                }
                if (paths[2].move_left()) {
                    p.push(make_pair(paths[2].get_heuristic(), paths[2]));
                }
                break;
            case 'R':
                if (paths[0].move_up()) {
                    p.push(make_pair(paths[0].get_heuristic(), paths[0]));
                }
                if (paths[1].move_down()) {
                    p.push(make_pair(paths[1].get_heuristic(), paths[1]));
                }
                if (paths[2].move_right()) {
                    p.push(make_pair(paths[2].get_heuristic(), paths[2]));
                }
                break;
            default:
                if (paths[0].move_up()) {
                    p.push(make_pair(paths[0].get_heuristic(), paths[0]));
                }
                if (paths[1].move_down()) {
                    p.push(make_pair(paths[1].get_heuristic(), paths[1]));
                }
                if (paths[2].move_left()) {
                    p.push(make_pair(paths[2].get_heuristic(), paths[2]));
                }
                if (paths[3].move_right()) {
                    p.push(make_pair(paths[3].get_heuristic(), paths[3]));
                }
        }
    }
    game_state *t = g_p;
    game_state *del;
    while (t != nullptr) {
        solution.push_front(t->get_last_move());
        del = t;
        t = t->get_prev_state();
        delete(del);
    }
    solution.pop_front();
}

const forward_list<char> &solver::get_solution() const {
    return solution;
}






