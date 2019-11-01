//

// Created by kevin on 19/10/19.

//

#include <stdlib.h>

#include <time.h>

#include<iostream>

#include "Matriz.h"

#include "Backtracking.h"

#include "Pathfinding.h"



void Matriz::hacerBacktracking() {

    Backtracking backtracking;

    backtracking.solve(8,1, matriz);



}



void Matriz::hacerPathfinding() {

    // Creating a shortcut for int, int pair type

    typedef pair<int, int> Pair;

    typedef pair<double, pair<int, int>> pPair;

    Pair src = make_pair(8, 1);

    Pair dest = make_pair(1, 1);





    Pathfinding pathfinding;

    pathfinding.aStarSearch(matriz,src,dest);

}

void Matriz::escribirMatriz(int x, int y){



    for(int i=0;i<12;i++){

        for(int j=0;j<12;j++){

            if (matriz[x][y]==1){

                matriz[x][y]=2;

            }

        }

    }

}

void Matriz::mostrarMatriz(){

    cout<<"================================================================================="<<endl;

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++)

            printf(" %d ", matriz[i][j]);

        printf("\n");

    }

    cout<<"================================================================================="<<endl;



}