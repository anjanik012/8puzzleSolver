#include <iostream>
#include <forward_list>
#include "solver.h"
#include "game_state.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Invalid arguments:-";
        return 1;
    }
    std::string in(argv[1]);
    game_state start_state(in);
    solver _solver(start_state);
    _solver.solve();
    std::forward_list<char> sol = _solver.get_solution();
    for (auto s: sol) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}