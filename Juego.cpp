//
// Created by adrian on 12/10/19.
//

#include <iostream>
#include "Juego.h"
#include "Matriz.h"
#include "Estudiantes.h"
#include "ListaCursos.h"
#include "ListaBalas.h"
#include "ListaEstudiantes.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <gobject/gvalue.h>
int num_oleadas=0;
int numg_eneracion=0;
int cant_repobados=0;
double probabilidad_mutaciones=0.0;
int cantidad_mutaciones=0;
int numero_de_estudiantes;
int x_pos;
int y_pos;
int contador=0;

bool new_oleada=true;
Matriz matrix;
int generador_de_zombies=0;
int numero_de_oleada=1;
bool balas=true;

bool ganomodo0=false;
bool ganomodo1=false;
GtkWidget* oleadas;
GtkWidget* generacion;
GtkWidget* reprobados;
GtkWidget* probabilidad ;
GtkWidget* cantidad;
int modo_de_juego;
int porcentaje_de_ap;



        /* Description of the Grid-
        1--> The cell is not blocked
        0--> The cell is blocked */

int matriz[12][12]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};



ListaCursos* listaCursos=new ListaCursos;
ListaEstudiantes* listaEstudiantes=new ListaEstudiantes;
ListaEstudiantes* listaEstudiantes_llegados=new ListaEstudiantes;
ListaBalas* listaBalas=new ListaBalas;
GtkWidget* fixed1;

void mover(){

    if(listaEstudiantes->getsize()>0){


    Estudiantes* ptr=listaEstudiantes->head;
        if(ptr->mov_estudiante->getsize()>0) {


            listaEstudiantes->display();
            listaEstudiantes->getsize();
            ptr->mov_estudiante->display();


            while (ptr != NULL) {

                if (ptr->mov_estudiante->getsize()>1) {


                    int x1 = 62 * (ptr->mov_estudiante->GetNth(0)->x - 1) + 128;
                    int y1 = 60 * (ptr->mov_estudiante->GetNth(0)->y - 1) + 6;
                    int x2 = 62 * (ptr->mov_estudiante->GetNth(1)->x - 1) + 128;
                    int y2 = 60 * (ptr->mov_estudiante->GetNth(1)->y - 1) + 6;


                    //gtk_fixed_move(GTK_FIXED(fixed1), ptr->image, y2, x2);
                    //gtk_widget_show_all(fixed1);
                    //ptr = ptr->next;
                    double cita = atan2(x2 - x1, y2 - y1);

                    double new_x_final = ptr->x_actual +ptr->getVelocidad()* cos(cita);
                    double new_y_final = ptr->y_actual +ptr->getVelocidad()* sin(cita);


                    if (y2 == (int) new_x_final && (x2 - 10 < (int) new_y_final) && (x2 + 10 > (int) new_y_final)) {
                        ptr->mov_estudiante->removeFirstNode();
                    }


                        if(new_y_final<(148)&&(ptr->validaciones>=porcentaje_de_ap) ){
                            ganomodo0=true;
                        }





                    gtk_fixed_move(GTK_FIXED(fixed1), ptr->image, new_x_final, new_y_final);
                    gtk_widget_show_all(fixed1);
                    ptr->x_actual = new_x_final;
                    ptr->y_actual = new_y_final;



                    //ptr->mov_estudiante->removeFirstNode();
                }
                    ptr = ptr->next;

            }
        }
    }
}


void actualizar(){
    mover();
};


Juego::Juego(int porcentajeDeAprobacion) : porcentaje_de_aprobacion(porcentajeDeAprobacion) {
    gtk_main_quit();
    tipo_de_juego=1;
    modo_de_juego=0;
    porcentaje_de_ap=porcentaje_de_aprobacion;
    iniciar_juego();
}

Juego::Juego(int porcentajeDeAprobacion, int numeroDeOleadasAJugar) : porcentaje_de_aprobacion(porcentajeDeAprobacion),
                                                                      numero_de_oleadas_a_jugar(numeroDeOleadasAJugar) {
    gtk_main_quit();
    tipo_de_juego=2;
    porcentaje_de_ap=porcentaje_de_aprobacion;
    iniciar_juego();
    modo_de_juego=1;
}


void nuevoEstudiante(int i) {

    int y = rand() % (11 - 1);
    GtkWidget *image = gtk_image_new();
    int pos = 0;
    std::string tipo;
    int tipo_num = 1 + rand() % (5 - 1);
    int yllegada = rand() % (11 - 1);

    switch (tipo_num) {
        case 1:
            gtk_image_set_from_file(GTK_IMAGE(image), "ogros.png");
            tipo = "Ogros";
            break;
        case 2:
            gtk_image_set_from_file(GTK_IMAGE(image), "hw.png");
            tipo = "ElfosOscuros";
            break;
        case 3:
            gtk_image_set_from_file(GTK_IMAGE(image), "merc.png");;
            tipo = "Harpias";
            break;
        case 4:
            gtk_image_set_from_file(GTK_IMAGE(image), "mercenario.png");
            tipo = "Mercenarios";
            break;
    }

    int pos_en_x = 60 * (y) + 6;
    int pos_en_y = 62 * 9 + 128;

    GdkPixbuf *pixbuf = gtk_image_get_pixbuf(GTK_IMAGE(image));

    pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60, 60, GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);

    List_Posiciones *listaPosiciones;

    if (i >= 13) {
        listaPosiciones = matrix.hacerPathfinding(matriz, y + 1, yllegada + 1);
    } else {
        listaPosiciones = matrix.hacerBacktracking(matriz, y + 1, yllegada + 1);
    }


    gtk_fixed_put(GTK_FIXED(fixed1), image, pos_en_x, pos_en_y);
    gtk_widget_show_all(fixed1);


    if (listaEstudiantes->getsize() < 4) {
        if(tipo.compare("Ogros")==0){
            listaEstudiantes->insert(10, y + 1, tipo, image, listaPosiciones, pos_en_x, pos_en_y, listaEstudiantes,1,3,1,1,1,1,"131111");

        }
        if(tipo.compare("ElfosOscuros")==0){
            listaEstudiantes->insert(10, y + 1, tipo, image, listaPosiciones, pos_en_x, pos_en_y, listaEstudiantes,2,3,1,1,3,2,"231132");

        }
        if(tipo.compare("Harpias")==0){
            listaEstudiantes->insert(10, y + 1, tipo, image, listaPosiciones, pos_en_x, pos_en_y, listaEstudiantes,3,9,2,9,2,2,"392922");

        }
        if(tipo.compare("Mercenarios")==0){
            listaEstudiantes->insert(10, y + 1, tipo, image, listaPosiciones, pos_en_x, pos_en_y, listaEstudiantes,3,3,3,1,3,3,"333133");
        }
    }
    else{
        listaEstudiantes->sorting();

        int tmp1, tmp2;

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,listaEstudiantes->getsize()-1);

        tmp1=dist6(rng);
        tmp2=tmp1;

        while (tmp1 == tmp2) {
            tmp2 = dist6(rng);

        }
        AlgoritmosGeneticos *algoritmosGeneticos;

        string chrom=algoritmosGeneticos->mate(listaEstudiantes->GetNth(tmp1), listaEstudiantes->GetNth(tmp2));
        string text="Cantidad de Mutaciones "+cantidad_mutaciones;
        gtk_label_set_text(GTK_LABEL(cantidad),text.c_str());
        int vida=chrom.at(0)- '0';
        int rarq=chrom.at(1)- '0';
        int rart=chrom.at(2)- '0';
        int rmag=chrom.at(3)- '0';
        int rlza=chrom.at(4)- '0';
        int velocidad=chrom.at(5)- '0';
        listaEstudiantes->insert(10, y + 1, tipo, image, listaPosiciones, pos_en_x, pos_en_y,listaEstudiantes,vida+20,rarq,rart,rmag,rlza,velocidad ,chrom);
    }





    }





void colocate_students (GtkWidget *widget, GtkWidget* fixed1) {


    if (new_oleada == true) {
        new_oleada = false;
        for (int i = 0; i < 3; i++) {
            nuevoEstudiante(i);
            numero_de_estudiantes++;


        }
    }
}
void colocate_students3 () {


    if (new_oleada == true) {
        new_oleada = false;
        for (int i = 0; i < 15; i++) {

            nuevoEstudiante(i);
            numero_de_estudiantes++;


        }
    }
}
void colocate2(){
    for (int i = 0; i < 3; i++) {
        numero_de_estudiantes++;

        nuevoEstudiante(i);
    }
}

GtkWidget* gtkImage;
GtkWidget* disparo(int posx,int posy){

    gtkImage=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(gtkImage),"bal.png");
    GdkPixbuf *pixbuf =	gtk_image_get_pixbuf(GTK_IMAGE(gtkImage));
    pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60,60, GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(GTK_IMAGE(gtkImage), pixbuf);
    gtk_fixed_put(GTK_FIXED(fixed1),gtkImage,6+posx*60,128+posy*62);
    gtk_widget_show_all(fixed1);

    return gtkImage;


}
void mov_disparo(GtkWidget* img,int posXEst, int posYEst){

    GValue x =  G_VALUE_INIT;
    GValue y =  G_VALUE_INIT;
    gtk_container_child_get_property(GTK_CONTAINER(fixed1), img, "x", g_value_init (&x, G_TYPE_INT));
    gtk_container_child_get_property(GTK_CONTAINER(fixed1), img, "y", g_value_init (&y, G_TYPE_INT));
    int posXBala=x.data->v_int;
    int posYBala=y.data->v_int;

    if(posXEst<posXBala){
        posXBala=posXBala-5;
    }
    if (posXEst==posXBala){
        if (posYEst>posYBala){
            posYBala=posYBala+5;
        }
        if (posYEst<posYBala){
            posYBala=posYBala-5;
        }
    }
    if (posXEst>posXBala){
        posXBala=posXBala+5;
    }
    if (posYEst<posYBala){
        posYBala=posYBala-5;
    }
    if (posYEst==posYBala){
        if (posXEst>posXBala){
            posXBala=posXBala+5;
        }
        if (posXEst<posXBala){
            posXBala=posXBala-5;
        }
    }
    if (posYEst>posYBala){
        posYBala=posYBala+5;
    }

    gtk_fixed_move(GTK_FIXED(fixed1),img,posXBala,posYBala);
    gtk_widget_show_all(fixed1);


}

void collide_check(){
    for(int i=0;i<listaBalas->getsize();i++){

        GValue x =  G_VALUE_INIT;
        GValue y =  G_VALUE_INIT;
        gtk_container_child_get_property(GTK_CONTAINER(fixed1), listaBalas->GetNth(i)->image, "x", g_value_init (&x, G_TYPE_INT));
        gtk_container_child_get_property(GTK_CONTAINER(fixed1), listaBalas->GetNth(i)->image, "y", g_value_init (&y, G_TYPE_INT));
        int posXBala=x.data->v_int;
        int posYBala=y.data->v_int;

            if(abs(listaBalas->GetNth(i)->objetivo->x_actual-posXBala)<=20&&abs(listaBalas->GetNth(i)->objetivo->y_actual-posYBala)<=22){

                gtk_widget_set_opacity(listaBalas->GetNth(i)->image,0);
                //listaBalas->GetNth(i)->objetivo->setVida( listaBalas->GetNth(i)->objetivo->getVida()-(listaBalas->GetNth(i)->torre->getCreditos()+listaBalas->GetNth(i)->torre->getHoras()+listaBalas->GetNth(i)->torre->getNivelDeExigencia()));
                if(listaBalas->GetNth(i)->objetivo->getVida()<=0){
                    //gtk_widget_set_opacity(listaBalas->GetNth(i)->objetivo->image,0);
                    //listaBalas->deleteNode(i);
                }
            }
    }

}
ListaEstudiantes* validation(Cursos* cursos){

    ListaEstudiantes* enrango=new ListaEstudiantes;

    int rango=0;

    if(strcmp(cursos->getTipo().c_str(),"Arqueros")== 0){
        rango=1;
    }
    else if(strcmp(cursos->getTipo().c_str(),"Magos")== 0){
        rango=2;

    }
    else if(strcmp(cursos->getTipo().c_str(),"Artilleros")== 0){
        rango=2;

    }
    else if(strcmp(cursos->getTipo().c_str(),"Lanzafuego") == 0){
        rango=3;

    }

    for(int i=0;i<listaEstudiantes->getsize();i++){
        listaEstudiantes->display();

        if(abs(listaEstudiantes->GetNth(i)->x_actual-(6+(cursos->x)*60))<=rango*60&&abs(listaEstudiantes->GetNth(i)->y_actual-(128+(cursos->y)*62))<=rango*62){
            enrango->insert(listaEstudiantes->GetNth(i)->x, listaEstudiantes->GetNth(i)->y,
                            listaEstudiantes->GetNth(i)->getTipo(), listaEstudiantes->GetNth(i)->image,
                            listaEstudiantes->GetNth(i)->mov_estudiante, listaEstudiantes->GetNth(i)->x_actual,
                            listaEstudiantes->GetNth(i)->y_actual, listaEstudiantes,listaEstudiantes->GetNth(i)->getVida(),listaEstudiantes->GetNth(i)->getResistenciaArqueros(),listaEstudiantes->GetNth(i)->getResistenciaArtilleros(),listaEstudiantes->GetNth(i)->getResistenciaMagos(),listaEstudiantes->GetNth(i)->getResistenciaLanzafuego(),listaEstudiantes->GetNth(i)->getVelocidad(),listaEstudiantes->GetNth(i)->getChromosome());
        }

    }


    return enrango;

}
gboolean game_loop (GtkWidget *widget, GdkFrameClock *clock, GtkWidget* mo) {

    if(!ganomodo0&&!ganomodo1) {
        if (contador == 10) {
            actualizar();
            contador = 0;

            if (listaBalas->getsize() > 0) {
                for (int i = 0; i < listaBalas->getsize(); i++) {
                    mov_disparo(listaBalas->GetNth(i)->image, listaBalas->GetNth(i)->objetivo->x_actual,
                                listaBalas->GetNth(i)->objetivo->y_actual);
                    collide_check();
                }
            }

        }

        if (modo_de_juego == 0) {


            if (generador_de_zombies == 500) {
                if (listaEstudiantes->getsize() > 0) {
                    for (int i = 0; i < listaCursos->getsize(); i++) {
                        ListaEstudiantes *tmp = validation(listaCursos->GetNth(i));
                        for (int j = 0; j < tmp->getsize(); j++) {
                            GtkWidget *imagedisp = disparo(listaCursos->GetNth(i)->x, listaCursos->GetNth(i)->y);
                            listaBalas->insert(tmp->GetNth(j)->x_actual, tmp->GetNth(j)->y_actual, imagedisp,
                                               tmp->GetNth(j),listaCursos->GetNth(j));
                        }
                    }
                }

                colocate2();
                generador_de_zombies = 0;
            }

            if (modo_de_juego == 1) {
                if (new_oleada==true) {

                    new_oleada==false;
                    if (listaEstudiantes->getsize()==0) {
                        if (listaEstudiantes->getsize() > 0) {
                            for (int i = 0; i < listaCursos->getsize(); i++) {
                                ListaEstudiantes *tmp = validation(listaCursos->GetNth(i));
                                for (int j = 0; j < tmp->getsize(); j++) {
                                    GtkWidget *imagedisp = disparo(listaCursos->GetNth(i)->x,
                                                                   listaCursos->GetNth(i)->y);
                                    listaBalas->insert(tmp->GetNth(j)->x_actual, tmp->GetNth(j)->y_actual, imagedisp,
                                                       tmp->GetNth(j), listaCursos->GetNth(j));
                                }
                            }
                        }


                        colocate_students3();
                        generador_de_zombies = 0;
                        numero_de_oleada = numero_de_oleada + 1;
                        if (numero_de_oleada == num_oleadas) {
                            string text = "Oleada " + numero_de_oleada;
                            gtk_label_set_text(GTK_LABEL(oleadas), text.c_str());
                            ganomodo1 == true;
                        }

                    }
                }
            }
        }
        generador_de_zombies = generador_de_zombies + 1;
        contador = contador + 1;
    }
    else{
        GtkWidget* label;
        label=gtk_label_new("Termino");
        gtk_fixed_put(GTK_FIXED(fixed1),label,200,200);
        gtk_widget_show_all(fixed1);
    }
}





void on_key_press (GtkWidget *widget, GdkEventButton *event, GtkWidget* combobox) {

    if(5<=event->x && event->x<=610 && 125 <=event->y&&event->y<=750) {
        gtk_widget_set_opacity(combobox,1);
        x_pos=event->x;
        y_pos=event->y;

    }

}

void on_key_press2 (GtkWidget *widget, GdkEventKey *event) {
    GdkDisplay *display;
    GdkDeviceManager *device_manager;
    GdkDevice *device;
    Cursos* to_delete=new Cursos;
    Cursos* to_upgrade=new Cursos;
    int x, y;
    switch (event->keyval) {
        case GDK_KEY_e:
            display = gdk_display_get_default ();
            device_manager = gdk_display_get_device_manager (display);
            device = gdk_device_manager_get_client_pointer (device_manager);
            gdk_window_get_device_position(gtk_widget_get_window(widget),device, &x, &y, NULL);
            to_delete=listaCursos->search(floor((x_pos-6)/60),floor((y_pos-128)/62));



            gtk_widget_destroy(to_delete->image);
            break;

        case GDK_KEY_a:
            display = gdk_display_get_default ();
            device_manager = gdk_display_get_device_manager (display);
            device = gdk_device_manager_get_client_pointer (device_manager);
            gdk_device_get_position (device, NULL, &x, &y);
            to_upgrade=listaCursos->search(floor((x_pos-6)/60),floor((y_pos-128)/62));
            to_upgrade->mejorar();
            break;


    }

}

void deleteCurso(GtkWidget *widget, GdkEventButton *event){
    if(5<=event->x && event->x<=610 && 125 <=event->y&&event->y<=750) {
    }

}

void on_changed (GtkWidget *widget, GtkWidget* fixed1) {
    std::string txt = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(widget));
    gtk_widget_set_opacity(widget,0);

  GtkWidget *button_20;
  GtkWidget* image;
    GtkWidget* label;
    button_20=gtk_button_new();

    image=gtk_image_new();
    label=gtk_label_new("0");
    int pos=0;


    if(strcmp(txt.c_str(),"Arqueros")== 0){
        gtk_image_set_from_file(GTK_IMAGE(image),"archer.png");
    }
    else if(strcmp(txt.c_str(),"Magos")== 0){
        gtk_image_set_from_file(GTK_IMAGE(image),"magia2.png");

    }
    else if(strcmp(txt.c_str(),"Artilleros")== 0){
        gtk_image_set_from_file(GTK_IMAGE(image),"trt.png");

    }
    else if(strcmp(txt.c_str(),"Lanzafuego") == 0){
        gtk_image_set_from_file(GTK_IMAGE(image),"inferon.png");

    }

    GdkPixbuf *pixbuf =	gtk_image_get_pixbuf(GTK_IMAGE(image));

    pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60,60, GDK_INTERP_BILINEAR);

    int numx=floor((x_pos-6)/60);
    int numy=floor((y_pos-128)/62);


    matrix.escribirMatrizgeneral(numy+1,numx+1,matriz);


    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
    if(strcmp(txt.c_str(),"")!=0) {
        listaCursos->insert(numx, numy, txt, image,label);
    }
    //gtk_button_set_image (GTK_BUTTON (button_20), image);
    gtk_fixed_put(GTK_FIXED(fixed1),image,6+numx*60,128+numy*62);
    gtk_fixed_put(GTK_FIXED(fixed1),label,6+numx*60,128+numy*62);
    gtk_widget_show_all(fixed1);

}


void Juego::iniciar_juego() {
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *button_1;
    GtkWidget *button_2;
    GtkWidget *button_3;
    GtkWidget *title;
    GtkWidget *combobox;
    GtkWidget *comboboxcursos;
    GtkWidget *comboboxupgrades;


    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 700,830);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window),"CE vs Estudiantes");

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);

    image = gtk_image_new_from_file("tablero3.png");
    gtk_window_set_title(GTK_WINDOW(window),"CE vs Estudiantes");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);


    gtk_widget_show(layout);

    fixed1 = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(layout), fixed1);


    oleadas=gtk_label_new("");
    gtk_label_set_text(GTK_LABEL(oleadas),"");


    reprobados=gtk_label_new("");
    gtk_label_set_text(GTK_LABEL(oleadas),"Reprobados: ");

    probabilidad=gtk_label_new("Probabilidad: 10%");
    gtk_label_set_text(GTK_LABEL(oleadas),"Probabilidad de mutaciones: 10%");

    cantidad=gtk_label_new("Cantidad: ");
    gtk_label_set_text(GTK_LABEL(oleadas),"Cantidad de mutaciones: ");


    button_1=gtk_button_new();
    button_2=gtk_button_new();
    button_3=gtk_button_new();

    gtk_button_set_label(GTK_BUTTON(button_3),"Iniciar oleada");

    combobox=gtk_combo_box_text_new ();
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Arqueros");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Magos");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Artilleros");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Lanzafuego");



    gtk_widget_set_size_request(button_1,50,50);
    gtk_widget_set_size_request(button_2,300,100);
    gtk_widget_set_size_request(button_3,110,40);


    gtk_fixed_put(GTK_FIXED(fixed1),combobox,0,0);
    gtk_fixed_put(GTK_FIXED(fixed1),button_3,100,80);
    gtk_fixed_put(GTK_FIXED(fixed1),oleadas,380,30);
    gtk_fixed_put(GTK_FIXED(fixed1),generacion,380,50);

    gtk_fixed_put(GTK_FIXED(fixed1),reprobados,380,70);
    gtk_fixed_put(GTK_FIXED(fixed1),probabilidad,380,80);

    gtk_fixed_put(GTK_FIXED(fixed1),cantidad,380,100);


    gtk_widget_set_opacity(combobox,0);
    int i=432133;


    gtk_widget_add_tick_callback(fixed1, reinterpret_cast<GtkTickCallback>(game_loop), NULL, NULL);
    g_signal_connect (window, "button_press_event", G_CALLBACK (on_key_press), combobox);
    g_signal_connect (window, "key_press_event", G_CALLBACK (on_key_press2),NULL);

    g_signal_connect (combobox,"changed",G_CALLBACK (on_changed),fixed1);
    g_signal_connect(button_3, "clicked",G_CALLBACK(colocate_students), NULL);

    gtk_widget_show_all(window);

    gtk_main();

}

int Juego::getPorcentajeDeAprobacion() const {
    return porcentaje_de_aprobacion;
}

void Juego::setPorcentajeDeAprobacion(int porcentajeDeAprobacion) {
    porcentaje_de_aprobacion = porcentajeDeAprobacion;
}

int Juego::getNumeroDeOleadasAJugar() const {
    return numero_de_oleadas_a_jugar;
}

void Juego::setNumeroDeOleadasAJugar(int numeroDeOleadasAJugar) {
    numero_de_oleadas_a_jugar = numeroDeOleadasAJugar;
}
