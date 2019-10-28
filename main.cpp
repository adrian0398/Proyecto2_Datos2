#include <iostream>
#include "AlgoritmosGeneticos.h"
#include "Individual.h"
#include <gtk/gtk.h>
#include "Juego.h"

void close_window(GtkWidget* window){
    gtk_window_close(GTK_WINDOW(window));

}
void gameloop(GtkWidget *entry,GtkWidget* window){
    close_window(window);
    cout<<gtk_entry_get_text(GTK_ENTRY(entry))<<endl;
    int tmp=atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
    Juego juego(tmp);

}

void gameloop2(GtkWidget *entry2,GtkWidget *entry){
    GtkWidget *window = (GtkWidget*) g_object_get_data(G_OBJECT(entry2), "window");
    close_window(window);



    cout<<gtk_entry_get_text(GTK_ENTRY(entry))<<endl;
    cout<<gtk_entry_get_text(GTK_ENTRY(entry2))<<endl;
    int tmp=atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
    int tmp2=atoi(gtk_entry_get_text(GTK_ENTRY(entry2)));
    Juego juego(tmp,tmp2);
    gtk_main_quit();

}
void gameloop_param(GtkWidget *widget,GtkWidget *window){

    close_window(window);


    if(!strcmp(gtk_button_get_label(GTK_BUTTON(widget)),"Modo survival")){
        cout<<"Modo survival"<<endl;

        GtkWidget* tmp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(tmp), 500,200);
        gtk_window_set_position(GTK_WINDOW(tmp), GTK_WIN_POS_CENTER);

        GtkWidget * box=gtk_box_new (GTK_ORIENTATION_VERTICAL,10);

        GtkWidget* title=gtk_label_new("");
        gtk_label_set_text(GTK_LABEL(title),"Porcentaje de cursos a evaluar");


        GtkWidget * entry=gtk_entry_new ();


        gtk_container_add(GTK_CONTAINER(tmp), box);


        gtk_box_pack_start (GTK_BOX (box), title, TRUE,TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box), entry, TRUE,TRUE, 0);



        g_signal_connect(entry, "activate",G_CALLBACK(gameloop), tmp);

        gtk_widget_show_all(tmp);
        gtk_main();


    }

    if(!strcmp(gtk_button_get_label(GTK_BUTTON(widget)),"Modo por oleadas")){
        cout<<"Modo por oleadas"<<endl;
        GtkWidget* tmp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(tmp), 500,200);
        gtk_window_set_position(GTK_WINDOW(tmp), GTK_WIN_POS_CENTER);

        GtkWidget * box=gtk_box_new (GTK_ORIENTATION_VERTICAL,10);

        GtkWidget* title=gtk_label_new("");
        gtk_label_set_text(GTK_LABEL(title),"Porcentaje de cursos a evaluar");


        GtkWidget * entry=gtk_entry_new ();



        GtkWidget* title2=gtk_label_new("");
        gtk_label_set_text(GTK_LABEL(title2),"# de Oleadas");


        GtkWidget * entry2=gtk_entry_new ();


        gtk_container_add(GTK_CONTAINER(tmp), box);


        gtk_box_pack_start (GTK_BOX (box), title, TRUE,TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box), entry, TRUE,TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box), title2, TRUE,TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box), entry2, TRUE,TRUE, 0);

        GData* data;

        g_object_set_data(G_OBJECT(entry2), "window", tmp);
        g_signal_connect(entry2, "activate",G_CALLBACK(gameloop2), entry);
        gtk_widget_show_all(tmp);


        gtk_main();
    }
    //gtk_main_quit();

}



GtkWindow intro_window(){
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

    image = gtk_image_new_from_file("background_intro.jpg");
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
    gtk_fixed_put(GTK_FIXED(fixed),button_1,200,300);
    gtk_fixed_put(GTK_FIXED(fixed),button_2,200,450);

    g_signal_connect(button_1, "clicked",G_CALLBACK(gameloop_param), window);
    g_signal_connect(button_2, "clicked",G_CALLBACK(gameloop_param), window);

    gtk_widget_show_all(window);


    gtk_main();


}




int main() {
   // GtkWindow intro=intro_window();
    //std::cout << "Hello, World!" << std::endl;
   // Individual* i;
    //i->run();
    AlgoritmosGeneticos* algoritmosGeneticos;
    algoritmosGeneticos->run();
}




