#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *label;
} AppWidgets;

// This will be called when the button is clicked to display text
static void on_display_text_button_clicked(GtkWidget *widget, AppWidgets *app) {
    static gboolean toggled = FALSE;
    
    // Toggle between two messages
    if (toggled) {
        gtk_label_set_text(GTK_LABEL(app->label), "Text I guess...");
    } else {
        gtk_label_set_text(GTK_LABEL(app->label), "Button clicked! Awsum text displayed!");
    }
    
    toggled = !toggled;
}

int main(int argc, char *argv[]) {
    GtkWidget *display_text_button, *close_button, *vbox;
    AppWidgets *app;
    
    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Allocate app structure
    app = g_new(AppWidgets, 1);
    
    // Create the main window
    app->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app->window), "Awsum Window");
    gtk_window_set_default_size(GTK_WINDOW(app->window), 1920, 1080);
    gtk_container_set_border_width(GTK_CONTAINER(app->window), 10);
    g_signal_connect(app->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Create widgets
    display_text_button = gtk_button_new_with_label("Toggle Text");
    close_button = gtk_button_new_with_label("Close Window");
    app->label = gtk_label_new("Text I guess...");
    
    // Style the label
    gtk_widget_set_margin_bottom(app->label, 20);
    
    // Connect signals
    g_signal_connect(display_text_button, "clicked", 
                     G_CALLBACK(on_display_text_button_clicked), app);
    g_signal_connect(close_button, "clicked", 
                     G_CALLBACK(gtk_widget_destroy), app->window);
    
    // Create layout with better spacing
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_box_pack_start(GTK_BOX(vbox), app->label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), display_text_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), close_button, FALSE, FALSE, 0);
    
    // Center the box in the window
    GtkWidget *center_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(center_box), TRUE);
    gtk_box_pack_start(GTK_BOX(center_box), vbox, FALSE, FALSE, 0);
    // Add layout to window and display
    gtk_container_add(GTK_CONTAINER(app->window), center_box);
    gtk_widget_show_all(app->window);
    // Start main loop
    gtk_main();
    
    // Clean up
    g_free(app);
    return 0;
}
