//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_BACKTRACKING_H
#define PROYECTO2_DATOS2_BACKTRACKING_H
//
// Created by kevin on 12/10/19.
//
#include <stdio.h>
#include "List_Posiciones.h"

using namespace std;
class Backtracking {

    List_Posiciones* path=new List_Posiciones;
    int counter = 0;
    // Get the start location (x,y) and try to solve the maze
    // Backtracking method
    bool step (int x, int y,int maze[12][12]) {
        counter++;
        /* Accept case - we found the exit */
        if (maze[x][y] == 2) {
            matrizSol[x][y]=3;
            path->insert(x, y);
            return true;
        }
        /* Reject case - we hit a wall or our path */
        if (maze[x][y] == 0 || maze[x][y]==3 || maze[x][y] == 8) {
            return false;
        }
        /* Backtracking Step */
        // Mark this location as part of our path
        maze[x][y]=3;
        matrizSol[x][y]=3;
        path->insert(x, y);
        bool result;
        // Try to go Up
        if(maze[x-1][y] != 0 && maze[x-1][y]!=3 && maze[x-1][y] != 8){
            result = step(x-1, y,maze);
            if (result) { return true;}
        }
            // Try to go Left
        else if(maze[x][y-1] != 0 && maze[x][y-1]!=3 && maze[x][y-1] != 8){
            result = step(x, y-1,maze);
            if (result) { return true;}
        }
        // Try to go Right
        if(maze[x][y+1] != 0 && maze[x][y+1]!=3 && maze[x][y+1] != 8){
            result = step(x, y+1,maze);
            if (result) { return true;}
        }

        // Try to go Down
        if(maze[x+1][y] != 0 && maze[x+1][y]!=3 && maze[x+1][y] != 8){
            result = step(x+1, y,maze);
            if (result) { return true;}
        }



        /* Deadend - this location can't be part of the solution */
        // Unmark this location
        maze[x][y] = 8;
        matrizSol[x][y]=8;
        path->removeLastNode();
        // Go back
        return false;
    }


public:
    List_Posiciones * solve(int x, int y,int maze[12][12]) {

        if (step(x,y,maze)) {
            //maze[x][y] = 4;
            matrizSol[x][y]=4;
        }
        cout<<"================================================================================="<<endl;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++)
                printf(" %d ", matrizSol[i][j]);
            printf("\n");
        }
        cout<<"================================================================================="<<endl;
        return path;
    }



    int matrizSol[12][12]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

};



#endif //PROYECTO2_DATOS2_BACKTRACKING_H
