//
// Created by adrian on 12/10/19.
//

#ifndef PROYECTO2_DATOS2_ESTUDIANTES_H
#define PROYECTO2_DATOS2_ESTUDIANTES_H

#include <iostream>
#include <string>

using namespace std;

class Estudiantes {

    int vida;
    int velocidad;
    int resistencia_magos;
    int resistencia_arqueros;
    string tipo;
public:
    int getVida() const;

    void setVida(int vida);

    const string &getTipo() const;

    void setTipo(const string &tipo);

    int getVelocidad() const;

    void setVelocidad(int velocidad);

    int getResistenciaMagos() const;

    void setResistenciaMagos(int resistenciaMagos);

    int getResistenciaArqueros() const;

    void setResistenciaArqueros(int resistenciaArqueros);

    int getResistenciaArtilleros() const;

    void setResistenciaArtilleros(int resistenciaArtilleros);

    int getResistenciaLanzafuego() const;

    void setResistenciaLanzafuego(int resistenciaLanzafuego);

private:
    int resistencia_artilleros;
    int resistencia_lanzafuego;



};


#endif //PROYECTO2_DATOS2_ESTUDIANTES_H
