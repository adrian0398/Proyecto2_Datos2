/**
 *@file Backtracking.h
 * @author Kevin Alanis
 * @brief metodo que busca el camino disponible desde el origne del estudiante hasta la zona de aprobación
 */

#ifndef PROYECTO2_DATOS2_BACKTRACKING_H
#define PROYECTO2_DATOS2_BACKTRACKING_H
#include <stdio.h>
#include "List_Posiciones.h"

using namespace std;
class Backtracking {

    /**
     * @brief instancia de lista posiciones para almacenar el camino a seguir por el estudiante
     */
    List_Posiciones* path=new List_Posiciones;
    int counter = 0;
    /**
     * @brief metodo que valida si es posible llegar al destino
     * @param x posicion x del camino que va validando
     * @param y posicion y del camino que va validando
     * @param maze matriz lógica del tablero de juego
     * @return  un boolean, true si encuentra camino, un false si no lo hace
     */
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

/**
 * @brief metodo constructor
 */
public:
    /**
     * @brief metodo que resuelve el backtracking
     * @param x posicion de origen x
     * @param y posicion de origen y
     * @param maze matriz del tablero de juego
     * @return lista de las posiciones con el camino a seguir
     */
    List_Posiciones * solve(int x, int y,int maze[12][12]) {

        if (step(x,y,maze)) {
            //maze[x][y] = 4;
            matrizSol[x][y]=4;
        }
        /*for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++)
                printf(" %d ", matrizSol[i][j]);
            printf("\n");
        }*/
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
