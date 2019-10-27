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
    //mostrarMatriz();

}

void Matriz::hacerPathfinding() {
    // Creating a shortcut for int, int pair type
    typedef pair<int, int> Pair;
    typedef pair<double, pair<int, int>> pPair;

    srand(time(NULL));
    int x1 =rand() % (10 - 1);
    Pair src = make_pair(x1, 0);
    int x2 =rand() % (10 - 1);
    Pair dest = make_pair(x2, 9);


    Pathfinding pathfinding;
    pathfinding.aStarSearch(matriz,src,dest);
}
void Matriz::escribirMatriz(int x, int y){

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (matriz[x][y]==1){
                cout<<"entre al if"<<endl;
                matriz[x][y]=0;
            }
        }
    }
    mostrarMatriz();
    hacerPathfinding();
    hacerBacktracking();
}
void Matriz::mostrarMatriz(){
    cout<<"================================================================================="<<endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf(" %d ", matriz[i][j]);
        printf("\n");
    }
    cout<<"================================================================================="<<endl;

}


