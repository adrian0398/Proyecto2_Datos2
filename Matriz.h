//
// Created by adrian on 31/10/19.
//

#ifndef PROYECTO2_DATOS2_MATRIZ_H
#define PROYECTO2_DATOS2_MATRIZ_H


class Matriz {


    /* Description of the Grid-

    1--> The cell is not blocked

    0--> The cell is blocked */





public:

    int matriz[12][12]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                         { 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0 },

                         { 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },

                         { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },

                         { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },

                         { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },

                         { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },

                         { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0 },

                         { 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },

                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};





    void escribirMatriz(int x,int y);

    void hacerBacktracking();

    void hacerPathfinding();

    void mostrarMatriz();
};


#endif //PROYECTO2_DATOS2_MATRIZ_H
