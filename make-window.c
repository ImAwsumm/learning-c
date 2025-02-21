```#include <gtk/gtk.h>


static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    
    // start gtk
    gtk_init(&argc, &argv);

    // Create a top level window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    // set a title for the window
    gtk_window_set_title(GTK_WINDOW(window), "My first window");
    
    // set resolution or window size
    gtk_window_set_default_size(GTK_WINDOW(window), 1600, 900);

    // close the window when there's a signal
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // show the "window"
    gtk_widget_show_all(window);

    
    gtk_main();

    
    // gtk is so ez
    return 0;
}
```
