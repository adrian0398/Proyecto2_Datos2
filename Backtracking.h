//
// Created by kevin on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_BACKTRACKING_H
#define PROYECTO2_DATOS2_BACKTRACKING_H
#include <stdio.h>
#include "List_Posiciones.h"

using namespace std;
class Backtracking {

    List_Posiciones* listPosiciones=new List_Posiciones;
    int counter = 0;
    // Get the start location (x,y) and try to solve the maze
    // Backtracking method
    bool step (int x, int y,int maze[10][10]) {
        counter++;
        /* Accept case - we found the exit */
        if (maze[x][y] == 2) {
            listPosiciones->insert(x,y);
            return true;
        }
        /* Reject case - we hit a wall or our path */
        if (maze[x][y] == 0 || maze[x][y]==3) {
            return false;
        }
        /* Backtracking Step */
        // Mark this location as part of our path
        maze[x][y]=3;
        matrizSol[x][y]=3;
        listPosiciones->insert(x,y);
        bool result;

        // Try to go Right
        result = step(x, y+1,maze);
        if (result) { return true;}
        // Try to go Up
        result = step(x-1, y,maze);
        if (result) { return true;}
        // Try to go Left
        result = step(x, y-1,maze);
        if (result) { return true;}
        // Try to go Down
        result = step(x+1, y,maze);

        if (result) { return true;}
        /* Deadend - this location can't be part of the solution */
        // Unmark this location
        maze[x][y] = 1;
        matrizSol[x][y]=1;
        listPosiciones->removeLastNode();
        // Go back
        return false;
    }


public:
    void solve(int x, int y,int maze[10][10]) {

        if (step(x,y,maze)) {
            maze[x][y] = 4;
            matrizSol[x][y]=4;
        }
        cout<<"================================================================================="<<endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                printf(" %d ", matrizSol[i][j]);
            printf("\n");
        }
        cout<<"================================================================================="<<endl;
        listPosiciones->display();
        cout<<"#################################################################"<<endl;
    }
    int matrizSol[10][10]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 2, 1, 1, 0, 1, 0, 1, 1, 0 },
                         { 0, 1, 1, 1, 0, 1, 0, 1, 0, 0 },
                         { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                         { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                         { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },
                         { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
                         { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0 },
                         { 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};





};
#endif //PROYECTO2_DATOS2_BACKTRACKING_H
