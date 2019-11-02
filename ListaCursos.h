//
// Created by adrian on 31/10/19.
//

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

            std::cout<<"tipo "<<ptr->getTipo()<<"Pos X: "<< ptr->x<<"Pos Y: "<<ptr->y <<" "<<endl;
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

    Cursos* removeLastNode()

    {

        if (head == NULL)

            return NULL;



        if (head->next == NULL) {

            delete head;

            return NULL;

        }



        // Find the second last node

        Cursos* second_last = head;

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

        Cursos* temp = head;

        head = head->next;



        delete temp;



    }





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

* Move through the list to the last that is NULL

*/

        while (last->next != NULL)

            last = last->next;



        last->next = new_node;

        return;

    }

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
