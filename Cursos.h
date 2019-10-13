//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_CURSOS_H
#define PROYECTO2_DATOS2_CURSOS_H

#include <string>

using namespace std;
class Cursos {
    string tipo;
    int creditos;
    int horas;
    int nivel_de_exigencia;
    int velocidad_de_evaluacion;
    int alcance_de_evaluacion;
    int rango;
    int tiempo_de_regeneracion_de_la_evaluacion_especial;
    int tiempo_de_regeneracion_de_la_evaluacion;
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

    int getTiempoDeRegeneracionDeLaEvaluacionEspecial() const;

    void setTiempoDeRegeneracionDeLaEvaluacionEspecial(int tiempoDeRegeneracionDeLaEvaluacionEspecial);

    int getTiempoDeRegeneracionDeLaEvaluacion() const;

    void setTiempoDeRegeneracionDeLaEvaluacion(int tiempoDeRegeneracionDeLaEvaluacion);


};


#endif //PROYECTO2_DATOS2_CURSOS_H
