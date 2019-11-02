#ifndef PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H
#define PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H

#include <string>
#include "Estudiantes.h"


using namespace std;
class AlgoritmosGeneticos {
public:

    string chromosome;
    int fitness;
    AlgoritmosGeneticos(string chromosome);
    AlgoritmosGeneticos mate(Estudiantes* padre1, Estudiantes* padre2);
    int cal_fitness();

    Estudiantes* run(Estudiantes* padre1, Estudiantes* padre2);


};


#endif //PROYECTO2_DATOS2_ALGORITMOSGENETICOSL_H