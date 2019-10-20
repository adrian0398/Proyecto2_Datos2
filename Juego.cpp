//
// Created by adrian on 12/10/19.
//

#include "Juego.h"



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

void Juego::iniciar_juego() {
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *button_1;
    GtkWidget *button_2;
    GtkWidget *title;


    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 700,700);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window),"CE vs Estudiantes");

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);

    image = gtk_image_new_from_file("tablero.png");
    gtk_window_set_title(GTK_WINDOW(window),"CE vs Estudiantes");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);


    gtk_widget_show(layout);
    GtkWidget *fixed;
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(layout), fixed);


    title=gtk_label_new("");
    gtk_label_set_text(GTK_LABEL(title),"CE vs Estudiantes");
    gtk_widget_modify_font (title,pango_font_description_from_string ("Black oak 50"));
    GdkColor color;
    gdk_color_parse ("white", &color);
    gtk_widget_modify_fg (title, GTK_STATE_NORMAL, &color);




    button_1=gtk_button_new();
    button_2=gtk_button_new();

    gtk_button_set_label(GTK_BUTTON(button_1),"Modo survival");
    gtk_button_set_label(GTK_BUTTON(button_2),"Modo por oleadas");

    gtk_widget_set_size_request(button_1,300,100);
    gtk_widget_set_size_request(button_2,300,100);


    gtk_fixed_put(GTK_FIXED(fixed),title,50,80);



    gtk_widget_show_all(window);


    gtk_main();

}
