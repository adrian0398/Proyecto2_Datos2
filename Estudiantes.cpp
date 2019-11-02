//
// Created by adrian on 12/10/19.
//

#include "Estudiantes.h"

int Estudiantes::getVida() const {
    return vida;
}

void Estudiantes::setVida(int vida) {
    Estudiantes::vida = vida;
}

int Estudiantes::getVelocidad() const {
    return velocidad;
}

void Estudiantes::setVelocidad(int velocidad) {
    Estudiantes::velocidad = velocidad;
}

int Estudiantes::getResistenciaMagos() const {
    return resistencia_magos;
}

void Estudiantes::setResistenciaMagos(int resistenciaMagos) {
    resistencia_magos = resistenciaMagos;
}

int Estudiantes::getResistenciaArqueros() const {
    return resistencia_arqueros;
}

void Estudiantes::setResistenciaArqueros(int resistenciaArqueros) {
    resistencia_arqueros = resistenciaArqueros;
}

int Estudiantes::getResistenciaArtilleros() const {
    return resistencia_artilleros;
}

void Estudiantes::setResistenciaArtilleros(int resistenciaArtilleros) {
    resistencia_artilleros = resistenciaArtilleros;
}

int Estudiantes::getResistenciaLanzafuego() const {
    return resistencia_lanzafuego;
}

void Estudiantes::setResistenciaLanzafuego(int resistenciaLanzafuego) {
    resistencia_lanzafuego = resistenciaLanzafuego;
}

const string &Estudiantes::getTipo() const {
    return tipo;
}

void Estudiantes::setTipo(const string &tipo) {
    Estudiantes::tipo = tipo;
}


void Estudiantes::set_properties() {

}