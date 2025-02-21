#include <gtk/gtk.h>

// this will be called when the button is clicked
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked!\n");
}

// This function will be called when the window is ALT f4'd (Closed) 
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {

    // start gtk
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    // set a title for the window
    gtk_window_set_title(GTK_WINDOW(window), "Awsum Window");

    // set resolution or window size
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);

    // close the window when a signal is received
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // make a button can set the label to "Awsum Button"
    GtkWidget *button = gtk_button_new_with_label("Awsum Button");

    //send a signal in the terminal when the button is clicked
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);
    
    //show the "window"
    gtk_widget_show_all(window);
    gtk_main();

    // gtk is so ez :)
    return 0;
}

