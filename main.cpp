#include <iostream>
#include "Backtracking.h"
#include "Pathfinding.h"
#include "Matriz.h"
int main() {
    Matriz matrix;
    matrix.hacerPathfinding();
    matrix.escribirMatriz(1, 1);
    matrix.hacerBacktracking();
    matrix.mostrarMatriz();
}