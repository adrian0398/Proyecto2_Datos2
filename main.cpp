#include <iostream>
#include "Backtracking.h"
#include "Pathfinding.h"
#define N 10
int main() {

    // Creating a shortcut for int, int pair type
    typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
    typedef pair<double, pair<int, int>> pPair;

    int maze[N][N] = { { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
                       { 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 },
                       { 0, 1, 0, 0, 0, 0, 1,0 ,0 , 0 },
                       { 1, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
                       {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
                       {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                       {0, 1, 0, 1, 1, 1, 0, 0, 0, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    Backtracking backtracking;
    backtracking.solveMaze(maze);

    cout<<"========================================================================"<<endl;

    Pathfinding pathfinding;
    /* Description of the Grid-
    1--> The cell is not blocked
    0--> The cell is blocked */

    // Source is the left-most bottom-most corner
    Pair src = make_pair(9, 0);
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);
    pathfinding.aStarSearch(maze, src, dest);

}