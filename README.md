# 8puzzle Solver

This is a basic api for solving 3x3 boards in  standard C++14. It has two main components:-

* _Game State_
* _Solver_

`game_state` provides a way to abstract the properties of a 3x3 board. A `solver` object is created with a `game_state` object.
Calling `solver::solve()` solves the input state and stores solution parameters in itself like _solution path_, _number of moves to solve_ 
and _number of nodes explored_.

`solver` object implements the **A-Star shortest path finding algorithm** with **number of tiles out of place heuristic**.

## Build Instructions

```sh
git clone https://github.com/anjanik012/8puzzleSolver.git
cd 8puzzleSolver
cmake
cd cmake-build-debug
make
```

## Run

### Input

A grid has an input format like this _127804365_, where a '0' represents the empty slot.

### Output

It outputs number of moves to get to the goal state(default is _123456780_) and the list of moves 
to get to the goal state.

```sh
./8puzzle 127804365
Number of moves:-24
R U L D R D L L U R D R U L U R D D L L U R R D
```

Moves are respect to the motion of empty tiles.

* **R** means the empty tile should move to right.
* **L** means the empty tile should move to left.
* **U** means the empty tile should move upwards.
* **D** means the empty tile should move downwards.

## Comments

Hardest inputs are _867254301_ and _647850321_ where both have the best solution in 31 moves. All other
problems can be solved in less than 30 moves. The algorithm used gaurantees the shortest path.
