//
// Created by adrian on 12/10/19.
//

#include <iostream>
#include "Juego.h"
#include <math.h>

int x_pos;
int y_pos;
int contador=0;
int numero_de_oleada;

GList * lista_cursos;
GList*  lista_estudiantes;
GtkWidget *fixed;


void actualizar(){};

Juego::Juego(int porcentajeDeAprobacion) : porcentaje_de_aprobacion(porcentajeDeAprobacion) {
    gtk_main_quit();
    tipo_de_juego=1;
    iniciar_juego();
}

Juego::Juego(int porcentajeDeAprobacion, int numeroDeOleadasAJugar) : porcentaje_de_aprobacion(porcentajeDeAprobacion),
                                                                      numero_de_oleadas_a_jugar(numeroDeOleadasAJugar) {
    gtk_main_quit();
    tipo_de_juego=2;
    iniciar_juego();
}


gboolean game_loop (GtkWidget *widget, GdkFrameClock *clock, GtkWidget* mo)
{

    actualizar();

    GValue x =  G_VALUE_INIT;
    GValue y =  G_VALUE_INIT;
    gtk_container_child_get_property(GTK_CONTAINER(widget), mo, "x", g_value_init (&x, G_TYPE_INT));
    gtk_container_child_get_property(GTK_CONTAINER(widget), mo, "y", g_value_init (&y, G_TYPE_INT));


    if(contador==20){
        //std::cout<<"entre"<<std::endl;
        gtk_fixed_move(GTK_FIXED(widget),GTK_WIDGET(mo),x.data->v_int+1.9,y.data->v_int+1);
        contador=0;

        for(int i=0;i<g_list_length(lista_cursos);i++){


            GValue x =  G_VALUE_INIT;
            GValue y =  G_VALUE_INIT;
            GtkWidget* child=GTK_WIDGET(g_list_nth_data(lista_cursos,i));
            gtk_container_child_get_property(GTK_CONTAINER(fixed), child, "x", g_value_init (&x, G_TYPE_INT));
            gtk_container_child_get_property(GTK_CONTAINER(fixed), child, "y", g_value_init (&y, G_TYPE_INT));

            std::cout<<"posiciones "<<x.data->v_int<<" y "<<y.data->v_int<<std::endl;

        }
    }
    contador=contador+1;
}





void on_key_press (GtkWidget *widget, GdkEventButton *event, GtkWidget* combobox) {

    if(5<=event->x && event->x<=610 && 125 <=event->y&&event->y<=750) {


        std::cout << "entre" << event->x << "posy" << event->y << std::endl;
        gtk_widget_set_opacity(combobox,1);
        x_pos=event->x;
        y_pos=event->y;

    }


}
void on_changed (GtkWidget *widget, GtkWidget* fixed) {
    std::string txt = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(widget));
    std::cout<<"You chose %s\n"<< txt<<"pox"<<x_pos<<"posy"<<y_pos<<"esti"<<std::endl;


    gtk_widget_set_opacity(widget,0);





  GtkWidget *button_20;
  GtkWidget* image;
    button_20=gtk_button_new();
    //gtk_button_set_label(GTK_BUTTON(button_20),txt.c_str());

    image=gtk_image_new();
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

    std::cout<<numx<<" efwfw "<<numy<<std::endl;

    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
    lista_cursos=g_list_append(lista_cursos,image);
    std::cout<<"Longitud "<<g_list_length(lista_cursos)<<std::endl;
    //gtk_button_set_image (GTK_BUTTON (button_20), image);
    gtk_fixed_put(GTK_FIXED(fixed),image,6+numx*60,128+numy*62);
    gtk_widget_show_all(fixed);






}


void Juego::iniciar_juego() {
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *button_1;
    GtkWidget *button_2;
    GtkWidget *title;
    GtkWidget *combobox;


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

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(layout), fixed);


    //title=gtk_label_new("");
    //gtk_label_set_text(GTK_LABEL(title),"CE vs Estudiantes");
    //gtk_widget_modify_font (title,pango_font_description_from_string ("Black oak 50"));
    //GdkColor color;
    //gdk_color_parse ("white", &color);
    //gtk_widget_modify_fg (title, GTK_STATE_NORMAL, &color);




    button_1=gtk_button_new();
    button_2=gtk_button_new();
    combobox=gtk_combo_box_text_new ();
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Arqueros");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Magos");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Artilleros");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combobox), "Lanzafuego");




    gtk_widget_set_size_request(button_1,50,50);
    gtk_widget_set_size_request(button_2,300,100);


    gtk_fixed_put(GTK_FIXED(fixed),button_1,50,80);
    gtk_fixed_put(GTK_FIXED(fixed),combobox,0,0);
    gtk_widget_set_opacity(combobox,0);
    int i=432133;


    gtk_widget_add_tick_callback(fixed, reinterpret_cast<GtkTickCallback>(game_loop), button_1, NULL);
    g_signal_connect (window, "button_press_event", G_CALLBACK (on_key_press), combobox);
    g_signal_connect (combobox,"changed",G_CALLBACK (on_changed),fixed);

    gtk_widget_show_all(window);

    gtk_main();

}
