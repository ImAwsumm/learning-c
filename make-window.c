#include <gtk/gtk.h>


int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "a-window-I-guess");
    gtk_window_set_default_size(GTK_WINDOW(window), 1600, 900);
    gtk_widget_show_all(window);
    gtk_main();

// not working ;(

// why is gtk so hard :(
    return 0;
}