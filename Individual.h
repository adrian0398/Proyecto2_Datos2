//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_INDIVIDUAL_H
#define PROYECTO2_DATOS2_INDIVIDUAL_H

#include <string>
#include "AlgoritmosGeneticos.h"
using namespace std;
class Individual {
public:

    string chromosome;
    int fitness;
    Individual(string chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();

    void run();


};


#endif //PROYECTO2_DATOS2_INDIVIDUAL_H
