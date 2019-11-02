//
// Created by adrian on 31/10/19.
//

#ifndef PROYECTO2_DATOS2_MATRIZ_H
#define PROYECTO2_DATOS2_MATRIZ_H

#include "List_Posiciones.h"


class Matriz {

public:

    void escribirMatriz(int x,int y,int matriz[12][12]);
    void escribirMatrizgeneral(int x,int y,int matriz[12][12]);

    List_Posiciones* hacerBacktracking(int matriz[12][12],int inicioy, int llegaday);

    List_Posiciones* hacerPathfinding(int matriz[12][12],int inicioy, int llegaday);

    void mostrarMatriz(int matriz[12][12]);
};


#endif //PROYECTO2_DATOS2_MATRIZ_H
