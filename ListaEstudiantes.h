/**
 *@file ListaEstudiantes.h
 * @author Adrián Lopez
 * @author Kevin Alanis
 * @brief Estructura que almacena estudiantes colocados en la matriz
 */
#ifndef PROYECTO2_DATOS2_LISTAESTUDIANTES_H
#define PROYECTO2_DATOS2_LISTAESTUDIANTES_H

#include <string>

#include <iostream>
#include "Estudiantes.h"
#include "AlgoritmosGeneticos.h"
#include <gtk/gtk.h>

using namespace std;
class ListaEstudiantes {
public:

    void display(){

        Estudiantes* ptr=new Estudiantes;

        ptr = head;

        while (ptr != NULL) {
            ptr = ptr->next;

        }
    }


public:
/**
    *@brief elimina al nodo final de la lista
    */
    Estudiantes* removeLastNode()

    {

        if (head == NULL)

            return NULL;
        if (head->next == NULL) {

            delete head;

            return NULL;

        }

        /**
        *@brief encuentra el penultimo nodo
        */

        Estudiantes* second_last = head;

        while (second_last->next->next != NULL)

            second_last = second_last->next;


        /**
         *@brief borra el ultimo nodo
        */

        delete (second_last->next);


        /**
        *@brief cambia next por el penultimo nodo
        */

        second_last->next = NULL;

        return head;

    }
/**
        *@brief elimina el primer nodo
        */
    void removeFirstNode()

    {
        /**
        *@brief mueve el head al siguiente nodo
        */


        Estudiantes* temp = head;

        head = head->next;

        delete temp;
    }
     /**
      * @brief inserta estudiante a la lista
      * @param x posicion final en x
      * @param y posicion final en y
      * @param tipo tipo de estudiante
      * @param image imagen del estudiante
      * @param listPosiciones lista del camino a seguir
      * @param actualx posicion actual en x del estudiante
      * @param actualy posicion actual en y del estudiante
      * @param listaEstudiantes lista de estudiantes
      * @param vida vida del estudiante
      * @param resistenciaarq resistencia a cursos arqueros
      * @param resistenciaart resistencia a cursos artilleros
      * @param resistenciamagos resistencia a cursos magos
      * @param resistencialanza resistencia a cursos lanza fuego
      * @param velocidad velocidad de movimiento del estudiante
      * @param chromosome cromosoma del estudiante
      */
    void insert(int x, int y, string tipo,GtkWidget* image, List_Posiciones* listPosiciones, double actualx, double actualy, ListaEstudiantes* listaEstudiantes, int vida, int resistenciaarq, int resistenciaart, int resistenciamagos, int resistencialanza, int velocidad, string chromosome ) {

        Estudiantes* new_node=new Estudiantes;

        Estudiantes* last=head;

        new_node->x = x;

        new_node->y = y;

        new_node->setTipo(tipo);

        new_node->image=image;
        new_node->mov_estudiante=listPosiciones;

        new_node->x_actual=actualx;
        new_node->y_actual=actualy;
        new_node->setChromosome(chromosome);
        new_node->setVelocidad(velocidad);
        new_node->setVida(vida);
        new_node->setResistenciaMagos(resistenciamagos);
        new_node->setResistenciaArtilleros(resistenciaart);
        new_node->setResistenciaArqueros(resistenciaarq);
        new_node->setResistenciaLanzafuego(resistencialanza);

        //new_node->listPosiblesPadres=listaEstudiantes;

        new_node->next = NULL;

        if (head == NULL)

        {
            head = new_node;

            return;

        }

/**

*@brief se mueve a travez de la lista hasta que este vacía

*/

        while (last->next != NULL)

            last = last->next;

        last->next = new_node;

        return;

    }
/**
 * @brief optiene el nodo a buscar
 * @param index posicion a obtener
 * @return nodo buscado
 */
    Estudiantes* GetNth( int index)
    {

        Estudiantes* curr = head;
        int count = 0;
        while (curr != NULL)
        {
            if (count == index)
                return(curr);
            count++;
            curr = curr->next;
        }

    }
/**
 * @brief optiene el largo de la lista
 * @return largo de la lista
 */
    int getsize() {
        int size=0;
        Estudiantes* ptr=new Estudiantes;
        ptr = head;
        while (ptr != NULL) {
            ptr = ptr->next;
            size=size+1;
        }
        return size;
    }
/**
 * @brief metodo que ordena los estudiantes
 */
    void sorting(){
        Estudiantes* cur1 = head;
        Estudiantes* cur2 = head;

        for (int i = 0; i < getsize(); i++) {
            for (int j = 0; j < getsize() - 1; j++) {
                if (cur1->fitness < cur2->fitness) {
                    int temp = cur1->fitness;
                    cur1->fitness = cur2->fitness;
                    cur2->fitness = temp;

                }
                cur2 = cur2->next;
            }
            cur2 = head;
            cur1 = head->next;
            for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
            }
        }
    }
    Estudiantes *head=NULL;
};

#endif //PROYECTO2_DATOS2_LISTAESTUDIANTES_H
