/**
 *@file Estudiantes.h
 * @author Adrián Lopez
 * @brief clase que funciona con el algoritmo genetico
 */
#ifndef PROYECTO2_DATOS2_INDIVIDUAL_H
#define PROYECTO2_DATOS2_INDIVIDUAL_H

#include <string>
#include "AlgoritmosGeneticos.h"
using namespace std;
class Individual {
public:

    string chromosome;
    int fitness;
    /**
     * @brief metodo que actualiza el cromosoma fitness del estudiante
     * @param chromosome cromosoma del estudiante
     */
    Individual(string chromosome);
    /**
     * @brief metodo que actualiza el cromosoma fitness del estudiante al mezclarle del padre 2
     * @param Individual cromosoma del estudiante padre
     */
    Individual mate(Individual parent2);
    int cal_fitness();

    void run();


};


#endif //PROYECTO2_DATOS2_INDIVIDUAL_H
