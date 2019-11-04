/**
 * @file Matriz.h
 * @author Kevin Alanis
 * @brief manejo de los metodos que trabajan sobre la matriz logica
 */
#ifndef PROYECTO2_DATOS2_MATRIZ_H
#define PROYECTO2_DATOS2_MATRIZ_H

#include "List_Posiciones.h"


class Matriz {

public:
/**
 * @brief escribe un valor en al matriz segun se requiera
 * @param x posicion en x a cambiar dato
 * @param y posicion en y a cambiar dato
 * @param matriz matriz de juego auxiliar
 */
    void escribirMatriz(int x,int y,int matriz[12][12]);
    /**
 * @brief escribe un valor en al matriz segun se requiera
 * @param x posicion en x a cambiar dato
 * @param y posicion en y a cambiar dato
 * @param matriz matriz de juego
 */
    void escribirMatrizgeneral(int x,int y,int matriz[12][12]);
/**
 * @brief metodo que llama al backtracking y le pasa los datos iniciales necesarios
 * @param matriz matriz de juego auxiliar
 * @param inicioy posicion y de inicio
 * @param llegaday posicion y de llegada
 * @return camino desde origen a destino
 */
    List_Posiciones* hacerBacktracking(int matriz[12][12],int inicioy, int llegaday);
    /**
 * @brief metodo que llama al pathfinding y le pasa los datos iniciales necesarios
 * @param matriz matriz de juego
 * @param inicioy posicion y de inicio
 * @param llegaday posicion y de llegada
 * @return camino desde origen a destino
 */
    List_Posiciones* hacerPathfinding(int matriz[12][12],int inicioy, int llegaday);

    void mostrarMatriz(int matriz[12][12]);
};


#endif //PROYECTO2_DATOS2_MATRIZ_H
