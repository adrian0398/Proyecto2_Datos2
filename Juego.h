//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_JUEGO_H
#define PROYECTO2_DATOS2_JUEGO_H
#include <gtk/gtk.h>
#include <thread>




class Juego {
    int tipo_de_juego;
    int puntaje;
    int numero_de_oleada;
    int generaciones_transcurridas;
    int estudiantes_repprobados;
    int fitness;
    int probabilidad_de_mutaciones;
    int cantidad_de_mutaciones;
    int probabilidad_de_inversiones;
    int cantidad_de_inversiones;
    int cantidad_de_estudiantes_aprobados;
    int porcentaje_de_aprobacion;
    int numero_de_oleadas_a_jugar;
public:
    Juego(int porcentajeDeAprobacion, int numeroDeOleadasAJugar);


public:
    Juego(int porcentajeDeAprobacion);
    void iniciar_juego();
    void printd();


public:


};


#endif //PROYECTO2_DATOS2_JUEGO_H
