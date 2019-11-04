/**
 *@file ListaBalas.h
 * @author Adrián Lopez
 * @author Kevin Alanis
 * @brief Estructura que almacena balas
 */
#ifndef PROYECTO2_DATOS2_LISTABALAS_H
#define PROYECTO2_DATOS2_LISTABALAS_H

#include <string>

#include <iostream>
#include <gtk/gtk.h>
#include "Estudiantes.h"
#include "Cursos.h"

using namespace std;

/**

*@brief Nodo que almacena posiciones x, y, imagen de bala, estudiante objetivo

*/


class Balas {

public:

    int x, y;

    GtkWidget* image;

    Balas *next=NULL;

    Estudiantes* objetivo;

    const string &getTipoBala() const;

    void setTipoBala(const string &tipoBala);

    Cursos* torre;

};
/**

*@brief Linked list que guarda todas las balas disparadas

*/

class ListaBalas {

    /**
   *@brief muestra las balas
   *@brief usa el nodo tmp para desplegar cada nodo hasta que la lista esté vacía
   */
public:

    void display(){

        Balas* ptr=new Balas;

        ptr = head;

        while (ptr != NULL) {
            ptr = ptr->next;

        }
    }

public:
    Balas *head=NULL;

    /**
    *@brief elimina al nodo final de la lista
    */
    Balas* removeLastNode()

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

        Balas* second_last = head;

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

        Balas* temp = head;

        head = head->next;

        delete temp;
    }
    /**
     * @brief inserta balas a la lista
     * @param x posicion final en x
     * @param y posicion final en y
     * @param image imagen de la bala
     * @param objetivo estudiante objetivo
     * @param tipo tipo de curso que la dispara
     */
    void insert(int x, int y, GtkWidget* image, Estudiantes* objetivo, Cursos* tipo) {

        Balas* new_node=new Balas;

        Balas* last=head;

        new_node->x = x;

        new_node->y = y;
        new_node->image=image;
        new_node->objetivo=objetivo;
        new_node->torre=tipo;
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
    Balas* GetNth( int index) {
        if (head != NULL) {

            Balas *current = head;

            // the index of the
            // node we're currently
            // looking at
            int count = 0;
            while (current != NULL) {
                if (count == index)
                    return (current);
                count++;
                current = current->next;
            }
        }

    }
/**
 * @brief optiene el largo de la lista
 * @return largo de la lista
 */
    int getsize() {
        int size = 0;
        Balas *ptr = new Balas;
        ptr = head;
        while (ptr != NULL) {
            ptr = ptr->next;
            size = size + 1;
        }
        return size;
    }


    void deleteNode( int position)
    {
        // If linked list is empty
        if (head== NULL)
            return;

        // Store head node
        Balas* temp = head;

        // If head needs to be removed
        if (position == 0)
        {
            head= temp->next;   // Change head
            free(temp);               // free old head
            return;
        }

        // Find previous node of the node to be deleted
        for (int i=0; temp!=NULL && i<position-1; i++)
            temp = temp->next;

        // If position is more than number of ndoes
        if (temp == NULL || temp->next == NULL)
            return;

        // Node temp->next is the node to be deleted
        // Store pointer to the next of node to be deleted
        Balas *next = temp->next->next;

        // Unlink the node from linked list
        free(temp->next);  // Free memory

        temp->next = next;  // Unlink the deleted node from list
    }

};

#endif //PROYECTO2_DATOS2_LISTABALAS_H
