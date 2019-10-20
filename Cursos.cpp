//
// Created by adrian on 12/10/19.
//

#include "Cursos.h"

const string &Cursos::getTipo() const {
    return tipo;
}

void Cursos::setTipo(const string &tipo) {
    Cursos::tipo = tipo;
}

int Cursos::getCreditos() const {
    return creditos;
}

void Cursos::setCreditos(int creditos) {
    Cursos::creditos = creditos;
}

int Cursos::getHoras() const {
    return horas;
}

void Cursos::setHoras(int horas) {
    Cursos::horas = horas;
}

int Cursos::getNivelDeExigencia() const {
    return nivel_de_exigencia;
}

void Cursos::setNivelDeExigencia(int nivelDeExigencia) {
    nivel_de_exigencia = nivelDeExigencia;
}

int Cursos::getVelocidadDeEvaluacion() const {
    return velocidad_de_evaluacion;
}

void Cursos::setVelocidadDeEvaluacion(int velocidadDeEvaluacion) {
    velocidad_de_evaluacion = velocidadDeEvaluacion;
}

int Cursos::getAlcanceDeEvaluacion() const {
    return alcance_de_evaluacion;
}

void Cursos::setAlcanceDeEvaluacion(int alcanceDeEvaluacion) {
    alcance_de_evaluacion = alcanceDeEvaluacion;
}

int Cursos::getRango() const {
    return rango;
}

void Cursos::setRango(int rango) {
    Cursos::rango = rango;
}

int Cursos::getTiempoDeRegeneracionDeLaEvaluacionEspecial() const {
    return tiempo_de_regeneracion_de_la_evaluacion_especial;
}

void Cursos::setTiempoDeRegeneracionDeLaEvaluacionEspecial(int tiempoDeRegeneracionDeLaEvaluacionEspecial) {
    tiempo_de_regeneracion_de_la_evaluacion_especial = tiempoDeRegeneracionDeLaEvaluacionEspecial;
}

int Cursos::getTiempoDeRegeneracionDeLaEvaluacion() const {
    return tiempo_de_regeneracion_de_la_evaluacion;
}

void Cursos::setTiempoDeRegeneracionDeLaEvaluacion(int tiempoDeRegeneracionDeLaEvaluacion) {
    tiempo_de_regeneracion_de_la_evaluacion = tiempoDeRegeneracionDeLaEvaluacion;
}

int Cursos::getUpgrade() const {
    return upgrade;
}

void Cursos::setUpgrade(int upgrade) {
    Cursos::upgrade = upgrade;
}
