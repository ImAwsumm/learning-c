#include <gtk/gtk.h>
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit(); 
  // Ends GTK main loop and closes the application if required or if a signal is sent 
}


int main(int argc, char *argv[]) {
  
    // start "Initialize" GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  
    gtk_window_set_title(GTK_WINDOW(window), "Hello World - By ImAwsum");

  // set window resolution or the size (both)
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080); 

    // make the "Hello, World!" label  
    GtkWidget *label = gtk_label_new("Hello, World!");

  
  // Add the hello world label to the AWSUM window
    gtk_container_add(GTK_CONTAINER(window), label);

  
  // Connect the "destroy" event to the function to close the app (aka: alt f4)
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
  
  
  // show the window (finnaly)
    gtk_widget_show_all(window);
    gtk_main();

    return 0;

    //gtk is ez
}

