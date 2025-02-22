#include <gtk/gtk.h>

// this will be called when the button is clicked to display text
static void on_display_text_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Awsum Button clicked!\n");
}

// This function will be called when the window is ALT f4'd (Closed) 
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

// This will be called when the close button is clicked
static void on_close_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(GTK_WIDGET(data));  // Closes the window
}

int main(int argc, char *argv[]) {

    // start gtk
    gtk_init(&argc, &argv);

    // Actually reates the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    // set a title for the window (Awsum Window)
    gtk_window_set_title(GTK_WINDOW(window), "Awsum Window");

    // set resolution or window size
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);

    // close the window when a signal is received
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // make a button and set the label to "Awsum Button"
    GtkWidget *display_text_button = gtk_button_new_with_label("Display Text");

    // send a signal in the terminal when the button is clicked
    g_signal_connect(display_text_button, "clicked", G_CALLBACK(on_display_text_button_clicked), NULL);

    // make a second button to close the window
    GtkWidget *close_button = gtk_button_new_with_label("Close Window");

    // send a signal to close the window when the button is clicked
    g_signal_connect(close_button, "clicked", G_CALLBACK(on_close_button_clicked), window);

    // create a vertical box (vbox) to space the buttons from each other
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // add the buttons to the vbox
    gtk_box_pack_start(GTK_BOX(vbox), display_text_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), close_button, FALSE, FALSE, 0);

    // add the vbox to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    //show the "window"
    gtk_widget_show_all(window);
    gtk_main();

    // gtk is so ez :)
    return 0;
}
