//
// Created by kevin on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_BACKTRACKING_H
#define PROYECTO2_DATOS2_BACKTRACKING_H
#include <stdio.h>
#define N 10

class Backtracking {
/* C/C++ program to solve Rat in a Maze problem using
backtracking */


// Maze size


    bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
    void printSolution(int sol[N][N]);
    bool isSafe(int maze[N][N], int x, int y);

public:
    bool solveMaze(int maze[N][N]);
};


#endif //PROYECTO2_DATOS2_BACKTRACKING_H
