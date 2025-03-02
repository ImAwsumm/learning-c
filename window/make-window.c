#include <gtk/gtk.h>

// This will be called when the button is clicked to display text
static void on_display_text_button_clicked(GtkWidget *widget, GtkLabel *label) {
    gtk_label_set_text(label, "Button clicked! Awsum text displayed!");
}

// This function will be called when the window is closed
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Awsum Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    
    // Create widgets
    GtkWidget *display_text_button = gtk_button_new_with_label("Display Text");
    GtkWidget *close_button = gtk_button_new_with_label("Close Window");
    GtkWidget *label = gtk_label_new("Text I guess...");
    
    // Connect signals
    g_signal_connect(display_text_button, "clicked", 
                     G_CALLBACK(on_display_text_button_clicked), label);
    g_signal_connect(close_button, "clicked", 
                     G_CALLBACK(gtk_widget_destroy), window);
    
    // Create layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), display_text_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), close_button, FALSE, FALSE, 0);
    
    // Add layout to window and display
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);   
    // Start main loop
    gtk_main();
    
    return 0;
}
