#include <gtk/gtk.h>

// Function to update the label's text
static void on_button_clicked(GtkWidget *button, gpointer data) {
    GtkLabel *label = GTK_LABEL(data);
    gtk_label_set_text(label, "Awsum you clicked !"); 
    // Update the label text when the button is clicked
    // Even though this is the first line this will be the last update on the window 
}

// Function to close the window when the "destroy" event is triggered
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit(); // Ends GTK main loop and closes the application
}

int main(int argc, char *argv[]) {
  
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello World - By ImAwsum");

    // Set window resolution or the size (both)
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);

    // Create the "Hello, World!" label
    GtkWidget *label = gtk_label_new("Hello, World!");

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Click here !!");

    // Set up a box container to arrange the label and button vertically
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    // Connect the button click event to update the label text
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);

    // Connect the "destroy" event to the function to actually close the program
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // Add the vbox to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Show the window 
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
    return 0;
}
