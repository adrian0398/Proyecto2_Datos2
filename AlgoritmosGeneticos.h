/**
 * @file AlgoritmosGeneticos.h
 * @author Adrian Lopez
 * @brief metodo que evoluciona, mezcla y crea generaciones de estudiantes
 */
#ifndef PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H
#define PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H

#include <string>
#include "Estudiantes.h"


using namespace std;
class AlgoritmosGeneticos {
public:

/**
 * @brief hace fitness, mezcla entre estudiantes según su padre, mutaciones
 */
    int fitness;
    string mate(Estudiantes* padre1, Estudiantes* padre2);
    int cal_fitness(string chromo);


};


#endif //PROYECTO2_DATOS2_ALGORITMOSGENETICOSL_H