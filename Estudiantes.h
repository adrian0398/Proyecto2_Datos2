/**
 *@file Estudiantes.h
 * @author Adrián Lopez
 * author Kevin Alanis
 * @brief Estructura objeto de tipo estudiante que almacena los atributos del estudiante
 */
#ifndef PROYECTO2_DATOS2_ESTUDIANTES_H
#define PROYECTO2_DATOS2_ESTUDIANTES_H
#include <iostream>
#include <string>
#include <gtk/gtk.h>
#include "List_Posiciones.h"
using namespace std;

class Estudiantes {

    int vida;
    int velocidad;
    int resistencia_magos;
    int resistencia_arqueros;
    string tipo;
    /**
     * @brief metodo constructor
     */
public:
    /**
     * @brief metodo get que optiene la vida del estudiante
     */
    int getVida() const;
    /**
     * @brief metodo set que asigna la vida del estudiante
     */
    void setVida(int vida);
    /**
     * @brief metodo get que optiene el tipo de estudiante
     * @return retorna un string con el nombre del estudiante
     */
    const string &getTipo() const;
    /**
     * @brief le asigna el tipo de estudiante
     * @param tipo tipo de estudiante
     */
    void setTipo(const string &tipo);
    /**
     * @brief metodo get que optiene la velocidad de movimiento del estudiante
     */
    int getVelocidad() const;
    /**
     * @brief metodo get que asigna la velocidad de movimiento del estudiante
     */
    void setVelocidad(int velocidad);
    /**
     * @brief metodo get que obtiene la resistencia del estudiante a los cursos magos
     */
    int getResistenciaMagos() const;
    /**
     * @brief metodo set que asigna la resistencia del estudiante a los cursos magos
     */
    void setResistenciaMagos(int resistenciaMagos);
    /**
     * @brief metodo get que obtiene la resistencia del estudiante a los cursos arqueros
     */
    int getResistenciaArqueros() const;
    /**
     * @brief metodo set que asigna la resistencia del estudiante a los cursos arqueros
     */
    void setResistenciaArqueros(int resistenciaArqueros);
    /**
     * @brief metodo get que optiene la resistencia del estudiante a los cursos artilleros
     */
    int getResistenciaArtilleros() const;
    /**
     * @brief metodo set que asigna la resistencia del estudiante a los cursos artilleros
     */
    void setResistenciaArtilleros(int resistenciaArtilleros);
    /**
     * @brief metodo get que optiene la resistencia del estudiante a los cursos lanza fuego
     */
    int getResistenciaLanzafuego() const;
    /**
     * @brief metodo set que asigna la resistencia del estudiante a los cursos lanza fuego
     */
    void setResistenciaLanzafuego(int resistenciaLanzafuego);

    Estudiantes *next=NULL;

    GtkWidget* image;
    int x;
    int y;
    List_Posiciones* mov_estudiante;
    int x_llegada;
    int y_llegada;
    double x_actual;
    double y_actual;
    //ListaEstudiantes* listPosiblesPadres;

    string chromosome;

    int validaciones;
    /**
     * @brief metodo get que optiene el cromosoma del estudiante
     */
    const string &getChromosome() const;
    /**
     * @brief metodo set que asigna el cromosoma al estudiante
     */
    void setChromosome(const string &chromosome);

    int fitness;
private:
    int resistencia_artilleros;
    int resistencia_lanzafuego;
};


#endif //PROYECTO2_DATOS2_ESTUDIANTES_H
