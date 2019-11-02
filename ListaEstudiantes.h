//
// Created by adrian on 31/10/19.
//

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

            std::cout<<"tipo"<<ptr->getTipo()<<"Pos X: "<< ptr->x<<"Pos Y: "<<ptr->y <<" "<<endl;
            ptr = ptr->next;

        }

    }

    /*!

*Linked list method to insert at the end of the list.

* Pass movie data and make a node that saves all of it's info

@param[in]  newdata   name of the movie to be inserted

@param[in]  year   year of the movie to be inserted

@param[in]  IMBDlink   IMDB link to search the url elements

@param[in]  director   director  of the movie to be inserted
     */

public:

    Estudiantes* removeLastNode()

    {

        if (head == NULL)

            return NULL;



        if (head->next == NULL) {

            delete head;

            return NULL;

        }



        // Find the second last node

        Estudiantes* second_last = head;

        while (second_last->next->next != NULL)

            second_last = second_last->next;



        // Delete last node

        delete (second_last->next);



        // Change next of second last

        second_last->next = NULL;

        return head;

    }

    void removeFirstNode()

    {

        // Move the head pointer to the next node

        Estudiantes* temp = head;

        head = head->next;

        delete temp;

    }

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

* Move through the list to the last that is NULL

*/

        while (last->next != NULL)

            last = last->next;



        last->next = new_node;

        return;

    }

    Estudiantes* GetNth( int index)
    {

        Estudiantes* curr = head;

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
