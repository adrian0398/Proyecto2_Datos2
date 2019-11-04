/**
 *@file ListaCursos.h
 * @author Adrián Lopez
 * @author Kevin Alanis
 * @brief Estructura que almacena cursos colocados en la matriz
 */
#ifndef PROYECTO2_DATOS2_LISTACURSOS_H
#define PROYECTO2_DATOS2_LISTACURSOS_H
#include <string>

#include <iostream>

#include <gtk/gtk.h>
#include "Cursos.h"
using namespace std;

class ListaCursos {
public:

    void display(){

        Cursos* ptr=new Cursos;

        ptr = head;

        while (ptr != NULL) {
            ptr = ptr->next;

        }

    }
public:
/**
    *@brief elimina al nodo final de la lista
    */
    Cursos* removeLastNode()

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

        Cursos* second_last = head;

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

        Cursos* temp = head;

        head = head->next;

        delete temp;

    }

/**
     * @brief inserta cursos a la lista
     * @param x posicion final en x
     * @param y posicion final en y
     * @param image imagen del curso
     * @param label label donde el curso se mostrara
     * @param objetivo estudiante objetivo
     * @param tipo tipo de curso
     */
    void insert(int x, int y, string tipo,GtkWidget* image, GtkWidget* label) {

        Cursos* new_node=new Cursos;

        Cursos* last=head;

        new_node->x = x;

        new_node->y = y;

        new_node->setTipo(tipo);

        new_node->image=image;
        new_node->label=label;

        if(tipo.compare("Arqueros")){
            new_node->setCreditos(1);
            new_node->setHoras(2);
            new_node->setNivelDeExigencia(1);

        }
        if(tipo.compare("Magos")){
            new_node->setCreditos(2);
            new_node->setHoras(4);
            new_node->setNivelDeExigencia(2);

        }
        if(tipo.compare("Artilleros")){
            new_node->setCreditos(3);
            new_node->setHoras(6);
            new_node->setNivelDeExigencia(3);

        }
        if(tipo.compare("Lanzafuego")){
            new_node->setCreditos(4);
            new_node->setHoras(8);
            new_node->setNivelDeExigencia(4);

        }

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
    Cursos* GetNth( int index)
    {

        Cursos* curr = head;

        // the index of the
        // node we're currently
        // looking at
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
        Cursos* ptr=new Cursos;
        ptr = head;
        while (ptr != NULL) {
            ptr = ptr->next;
            size=size+1;
        }
        return size;
    }
/**
 * @brief busca un curso en la matriz
 * @param x posicion en x del curso
 * @param y posicion en y del curso
 * @return tmp curso
 */
    Cursos* search(int x, int y){
        Cursos* tmp=head;
        while (tmp != NULL){
            if (tmp->x==x && tmp->y==y)
            {
                printf("key found\n");
                return tmp;
            }
            tmp= tmp->next;
        }

    }

    Cursos *head=NULL;
};


#endif //PROYECTO2_DATOS2_LISTACURSOS_H
