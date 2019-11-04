/**
 *@file Cursos.h
 * @author Adrián Lopez
 * author Kevin Alanis
 * @brief Estructura objeto de tipo curso que almacena los atributos del curso
 */
#ifndef PROYECTO2_DATOS2_CURSOS_H
#define PROYECTO2_DATOS2_CURSOS_H

#include <string>
#include <gtk/gtk.h>

using namespace std;
class Cursos {
    string tipo;
    int horas;
    int nivel_de_exigencia;
    int velocidad_de_evaluacion;
    int alcance_de_evaluacion;
    int rango;
    int tiempo_de_regeneracion_de_la_evaluacion;
    int upgrade=0;
    /**
     * @brief metodo constructor que inicializa algunos metodos para subir de nivel los cursos
     */
public:
    int getUpgrade() const;

    void setUpgrade(int upgrade);

    Cursos *next=NULL;
    int x;
    GtkWidget* image;
    int y;
    GtkWidget* label;
    int creditos;
public:
    /**
     * @brief metodo get que optiene el tipo de curso
     * @return retorna un string con el nombre del curso
     */
    const string &getTipo() const;

    /**
     * @brief le asigna el tipo de curso
     * @param tipo tipo de curso
     */
    void setTipo(const string &tipo);
    /**
    * @brief metodo get que optiene la cantidad de creditos del curso
    */
    int getCreditos() const;
    /**
    * @brief metodo set que asigna la cantidad de creditos del curso
    */
    void setCreditos(int creditos);
    /**
    * @brief metodo get que optiene la cantidad de horas reales del curso
    */
    int getHoras() const;
    /**
    * @brief metodo set que asigna la cantidad de horas reales del curso
    */
    void setHoras(int horas);
    /**
    * @brief optiene la dificultad del curso
    * @return el nivel de exigencia del curso
    */
    int getNivelDeExigencia() const;
    /**
     * @brief asigna la dificultad del curso
     * @param nivelDeExigencia dificultad del curso
     */
    void setNivelDeExigencia(int nivelDeExigencia);

    int getVelocidadDeEvaluacion() const;

    void setVelocidadDeEvaluacion(int velocidadDeEvaluacion);

    int getAlcanceDeEvaluacion() const;

    void setAlcanceDeEvaluacion(int alcanceDeEvaluacion);

    int getRango() const;

    void setRango(int rango);

    int getTiempoDeRegeneracionDeLaEvaluacion() const;

    void setTiempoDeRegeneracionDeLaEvaluacion(int tiempoDeRegeneracionDeLaEvaluacion);
    /**
     * @brief metodo que mejora un curso
     */
    void mejorar();

};


#endif //PROYECTO2_DATOS2_CURSOS_H
