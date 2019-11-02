//

// Created by kevin on 19/10/19.

//

#include <stdlib.h>

#include <time.h>

#include<iostream>

#include "Matriz.h"

#include "Backtracking.h"

#include "Pathfinding.h"



List_Posiciones* Matriz::hacerBacktracking(int matriz[12][12], int inicioy, int llegaday) {

    Backtracking backtracking;
    int matriztmp[12][12];

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++)

            matriztmp[i][j]=matriz[i][j];

    }
    cout<<"222222222222222222222222222222222222222222222222222222222222222222"<<endl;
    mostrarMatriz(matriz);
    cout<<"222222222222222222222222222222222222222222222222222222222222222222"<<endl;
    escribirMatriz(1,llegaday,matriztmp);
    cout<<"000000000000000000000000000000000000000000000000000000000000000000"<<endl;
    mostrarMatriz(matriztmp);
    cout<<"000000000000000000000000000000000000000000000000000000000000000000"<<endl;
    return backtracking.solve(10,inicioy, matriztmp);
}


List_Posiciones* Matriz::hacerPathfinding(int matriz[12][12], int inicioy, int llegaday) {

    // Creating a shortcut for int, int pair type

    typedef pair<int, int> Pair;

    typedef pair<double, pair<int, int>> pPair;

    Pair src = make_pair(10, inicioy);

    Pair dest = make_pair(1, llegaday);

    Pathfinding pathfinding;

    return pathfinding.aStarSearch(matriz,src,dest);

}

void Matriz::escribirMatriz(int x, int y, int matriz[12][12]){



    for(int i=0;i<12;i++){

        for(int j=0;j<12;j++){

            if (matriz[x][y]==1){

                matriz[x][y]=2;

            }

        }

    }

}

void Matriz::escribirMatrizgeneral(int x, int y, int matriz[12][12]){



    for(int i=0;i<12;i++){

        for(int j=0;j<12;j++){

            if (matriz[x][y]==1){

                matriz[x][y]=0;

            }

        }

    }

}

void Matriz::mostrarMatriz(int matriz[12][12]){

    cout<<"================================================================================="<<endl;

    for (int i = 0; i < 12; i++) {

        for (int j = 0; j < 12; j++)

            printf(" %d ", matriz[i][j]);

        printf("\n");

    }

    cout<<"================================================================================="<<endl;



}