/**
 *@file Estudiantes.h
 * @author Adrián Lopez
 * author Kevin Alanis
 * @brief Estructura objeto de tipo estudiante que almacena los atributos del estudiante
 */
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

public:
    int porcentaje_de_aprobacion;
    int getPorcentajeDeAprobacion() const;

    void setPorcentajeDeAprobacion(int porcentajeDeAprobacion);

    int getNumeroDeOleadasAJugar() const;

    void setNumeroDeOleadasAJugar(int numeroDeOleadasAJugar);

private:
    int numero_de_oleadas_a_jugar;
public:
    /**
     * @brief metodo de juego colectivo
     * @param porcentajeDeAprobacion porcentaje de cursos que deben evaluar a un estudiante para que sea valida la aprovacion
     * @param numeroDeOleadasAJugar cantidad de oleadas de estudianes que se generaran
     */
    Juego(int porcentajeDeAprobacion, int numeroDeOleadasAJugar);


public:
    /**
     * @brief metodo de juego individual
     * @param porcentajeDeAprobacion porcentaje de cursos que deben evaluar a un estudiante para que sea valida la aprovacion
     */
    Juego(int porcentajeDeAprobacion);
    /**
     * @brief inicia el juego 
     */
    void iniciar_juego();


public:


};


#endif //PROYECTO2_DATOS2_JUEGO_H
