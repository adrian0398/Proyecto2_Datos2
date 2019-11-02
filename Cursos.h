//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_CURSOS_H
#define PROYECTO2_DATOS2_CURSOS_H

#include <string>
#include <gtk/gtk.h>

using namespace std;
class Cursos {
    string tipo;
    int creditos;
    int horas;
    int nivel_de_exigencia;
    int velocidad_de_evaluacion;
    int alcance_de_evaluacion;
    int rango;
    int tiempo_de_regeneracion_de_la_evaluacion;
    int upgrade;
public:
    int getUpgrade() const;

    void setUpgrade(int upgrade);

    Cursos *next=NULL;
    int x;
    GtkWidget* image;
    int y;
public:
    const string &getTipo() const;

    void setTipo(const string &tipo);

    int getCreditos() const;

    void setCreditos(int creditos);

    int getHoras() const;

    void setHoras(int horas);

    int getNivelDeExigencia() const;

    void setNivelDeExigencia(int nivelDeExigencia);

    int getVelocidadDeEvaluacion() const;

    void setVelocidadDeEvaluacion(int velocidadDeEvaluacion);

    int getAlcanceDeEvaluacion() const;

    void setAlcanceDeEvaluacion(int alcanceDeEvaluacion);

    int getRango() const;

    void setRango(int rango);

    int getTiempoDeRegeneracionDeLaEvaluacion() const;

    void setTiempoDeRegeneracionDeLaEvaluacion(int tiempoDeRegeneracionDeLaEvaluacion);


};


#endif //PROYECTO2_DATOS2_CURSOS_H
