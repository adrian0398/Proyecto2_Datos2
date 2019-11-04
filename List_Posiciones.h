/**
 *@file List_Posiciones.h
 * @author Adrián Lopez
 * @author Kevin Alanis
 * @brief Estructura que almacena posiciones
 */

#ifndef PROYECTO2_DATOS2_LIST_POSICIONES_H
#define PROYECTO2_DATOS2_LIST_POSICIONES_H

#include <string>

#include <iostream>

using namespace std;

/**

*@brief Nodo que almacena posiciones x & y

*/



class Node {

public:

    int x, y;

    Node *next=NULL;

};

/**

*@brief Linked list que guarda todas las posiciones de la matriz

*/

class List_Posiciones {

    /**
   *@brief muestra la matriz
   *@brief usa el nodo tmp para desplegar cada nodo hasta que la lista esté vacía
   */

public:

    void display(){

        Node* ptr=new Node;

        ptr = head;

        while (ptr != NULL) {
            ptr = ptr->next;

        }

    }



    /**
    *@brief inserta al final de la lista
    */


public:
    Node *head=NULL;

    Node* removeLastNode()

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


        Node* second_last = head;

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
        Node* temp = head;

        head = head->next;

        delete temp;
    }

    /**
     *@brief inserta datos a un nodo
     * @param x es la posición x que se desea guardar
     * @param y es la posición y que se desea guardar
     */
    void insert(int x, int y) {
        Node* new_node=new Node;

        Node* last=head;

        new_node->x = x;

        new_node->y = y;

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
    Node* GetNth( int index) {
        if (head != NULL) {

            Node *current = head;
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
            Node *ptr = new Node;
            ptr = head;
            while (ptr != NULL) {
                ptr = ptr->next;
                size = size + 1;
            }
            return size;
        }
};



#endif //PROYECTO2_DATOS2_LIST_POSICIONES_H
