#ifndef PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H
#define PROYECTO2_DATOS2_ALGORITMOSGENETICOS_H

#include <string>

using namespace std;
class AlgoritmosGeneticos {
public:

    string chromosome;
    int fitness;
    AlgoritmosGeneticos(string chromosome);
    AlgoritmosGeneticos mate(AlgoritmosGeneticos parent2);
    int cal_fitness();

    void run();


};


#endif //PROYECTO2_DATOS2_ALGORITMOSGENETICOSL_H