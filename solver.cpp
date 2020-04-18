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
#include <array>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using std::priority_queue;
using std::pair;
using std::vector;
using std::array;
using std::forward_list;
using std::greater;
using std::make_pair;
using std::cout;
using std::endl;
using std::move;
using std::unordered_set;

solver::solver(const game_state &input_state) : current_state(input_state) , nodes_explored(0){
}

void solver::solve() {
    priority_queue<pair<int, game_state>, vector<pair<int, game_state>>, greater<>> p;
    auto root = make_pair(current_state.get_heuristic(), current_state);
    p.push(root);
    std::vector<game_state> explored;
    game_state *g_p = nullptr;
    while (!p.empty()) {
        auto u = p.top();
        p.pop();
        explored.push_back(u.second);
        nodes_explored++;
        g_p = new game_state(u.second);
        if (g_p->is_goal_state()) {
            cout << "Number of moves:" <<g_p->get_n_moves() << endl;
            cout << "Nodes Explored:" << nodes_explored << endl;
            break;
        }
        array<game_state, 4> paths;
        paths[0] = paths[1] = paths[2] = paths[3] = game_state(*g_p, g_p);
//        if (paths[0].move_up()) {
//            auto i = std::find(explored.begin(), explored.end(), paths[0]);
//            if (i == explored.end() && g_p->get_last_move() != 'D') {
//                p.push(make_pair(paths[0].get_heuristic(), paths[0]));
//            }
//        }
/        if (paths[1].mo-ve_down()) {
//            auto i = std::find(explored.begin(), explored.end(), paths[1]);
//            if (i == explored.end() && g_p->get_last_move() != 'U') {
//                p.push(make_pair(paths[1].get_heuristic(), paths[1]));
//            }
//        }
//        if (paths[2].move_left()) {
//            auto i = std::find(explored.begin(), explored.end(), paths[2]);
//            if (i == explored.end() && g_p->get_last_move() != 'R') {
//                p.push(make_pair(paths[2].get_heuristic(), paths[2]));
//            }
//        }
//        if (paths[3].move_right()) {
//            auto i = std::find(explored.begin(), explored.end(), paths[3]);
//            if (i == explored.end() && g_p->get_last_move() != 'L') {
//                p.push(make_pair(paths[3].get_heuristic(), paths[3]));
//            }
//        }
        switch (g_p->get_last_move()) {
            case 'U':
                -if (paths[0].move_up()) {*-----------------------------------------------------------------------------------------------.
                ...2.**8-
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






