//
// Created by adrian on 31/10/19.
//

#ifndef PROYECTO2_DATOS2_LIST_POSICIONES_H
#define PROYECTO2_DATOS2_LIST_POSICIONES_H

#include <string>

#include <iostream>

using namespace std;

/*!

*Node that saves the data of the movie

*/



class Node {

public:

    int x, y;

    Node *next;

};

/*!

*Linked list to save all the movies get from the csv

*/

class List_Posiciones {



    /*!

   *Linked list method to display the linked list

   * Use tmp node to display each node until linked list is NULL



   */

public:

    void display(){

        Node* ptr=new Node;

        ptr = head;

        while (ptr != NULL) {

            std::cout<<"Pos X: "<< ptr->x<<"Pos Y: "<<ptr->y <<" "<<endl;

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

    Node* removeLastNode()

    {

        if (head == NULL)

            return NULL;



        if (head->next == NULL) {

            delete head;

            return NULL;

        }



        // Find the second last node

        Node* second_last = head;

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

        Node* temp = head;

        head = head->next;



        delete temp;



    }





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

* Move through the list to the last that is NULL

*/

        while (last->next != NULL)

            last = last->next;



        last->next = new_node;

        return;

    }

    Node *head=new Node;

};



#endif //PROYECTO2_DATOS2_LIST_POSICIONES_H
