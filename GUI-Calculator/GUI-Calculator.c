#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define MAX_EXPR_LEN 256
typedef struct {
    GtkWidget *result_label;
    GtkWidget *entry;
} CalculatorWidgets;

// CSS styling for the calculator
const char *css_data = 
    "window { background-color: #2e2e2e; }"
    "entry { font-size: 24px; font-weight: bold; margin: 10px; border-radius: 5px; background-color: #1e1e1e; color: white; min-height: 50px; }"
    "label { font-size: 18px; margin: 5px; color: #ffffff; }"
    "button { font-size: 18px; font-weight: bold; border-radius: 5px; min-height: 50px; min-width: 50px; margin: 4px; }"
    "button.number { background-color: #3a3a3a; color: white; }"
    "button.operator { background-color: #ff9500; color: white; }"
    "button.equal { background-color: #66bb6a; color: white; }"
    "button.clear { background-color: #ef5350; color: white; }";

static gboolean validate_input(const char *equation, GError **error) {
    if (!equation || strlen(equation) == 0) {
        g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                    "Empty expression (I can't calculate your thoughts... yet)");
        return FALSE;
    }
    int num_count = 0;
    int op_count = 0;
    char prev_char = ' ';
    gboolean in_number = FALSE;

    while (*equation) {
        if (isdigit(*equation) || *equation == '.') {
            if (!in_number) {
                num_count++;  // Starting a new number
                in_number = TRUE;
            }
        } else if (strchr("+-*/", *equation)) {
            op_count++;
            in_number = FALSE;  // No longer in a number
            if (strchr("+-*/", prev_char)) {
                g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                           "Invalid operator sequence (They're not playing nice together)");
                return FALSE;
            }
        } else if (*equation != ' ') {
            g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                       "Invalid character (What are you doing?)");
            return FALSE;
        } else {
            // A space character indicates we're no longer in a number
            in_number = FALSE;
        }   
        prev_char = *equation;
        equation++;
    }
    if (num_count == 0) {
        g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                    "No numbers in expression (I'm not a magician, I need you to type something");
        return FALSE;
    }
    
    if (num_count != op_count + 1) {
        g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                    "Mismatched numbers and operators");
        return FALSE;
    }
    return TRUE;
}

static double calculate(const char *equation, GError **error) {
    if (!validate_input(equation, error)) {
        return 0.0;
    }

    // Arrays to store our numbers and operators
    double numbers[MAX_EXPR_LEN];
    char operators[MAX_EXPR_LEN];
    int num_count = 0, op_count = 0;
    char eq[MAX_EXPR_LEN];
    g_strlcpy(eq, equation, MAX_EXPR_LEN);
    
    // Time to split this equation
    char *token = strtok(eq, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            char *endptr;
            numbers[num_count] = strtod(token, &endptr);
            if (*endptr != '\0') {
                g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                           "Invalid number format");
                return 0.0;
            }
            num_count++;
        } else if (strchr("+-*/", token[0]) != NULL) {
            operators[op_count++] = token[0];
        }
        token = strtok(NULL, " ");
    }
    
    // Time for multiplication and division
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            if (operators[i] == '*') {
                numbers[i] *= numbers[i + 1];
            } else {
                if (fabs(numbers[i + 1]) < 1e-10) {
                    g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                              "Division by zero (Nice try, but infinity isn't a number here)");
                    return 0.0;
                }
                numbers[i] /= numbers[i + 1];
            }
            // Shift the numbers
            memmove(&numbers[i + 1], &numbers[i + 2],
                   (num_count - i - 2) * sizeof(double));
            memmove(&operators[i], &operators[i + 1],
                   (op_count - i - 1) * sizeof(char));
            num_count--;
            op_count--;
            i--;
        }
    }
    
    // Now for addition and subtraction
    double result = numbers[0];
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else if (operators[i] == '-') {
            result -= numbers[i + 1];
        }
    }
    return result;
}

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    CalculatorWidgets *widgets = (CalculatorWidgets *)data;
    const char *button_text = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(widgets->entry));
    
    char new_text[MAX_EXPR_LEN];
    if (strcmp(button_text, "C") == 0) {
        // Clear everything
        gtk_entry_set_text(GTK_ENTRY(widgets->entry), "");
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "Result: 0.00");
    } else if (strcmp(button_text, "=") == 0) {
        // Calculate!
        GError *error = NULL;
        
        // Check if the input is empty first
        if (strlen(current_text) == 0) {
            gtk_label_set_text(GTK_LABEL(widgets->result_label), "Error: No expression entered");
            return;
        }
        double result = calculate(current_text, &error);

        // Handle errors
        if (error != NULL) {
            gchar *error_msg = g_strdup_printf("Error: %s", error->message);
            gtk_label_set_text(GTK_LABEL(widgets->result_label), error_msg);
            g_free(error_msg);
            g_error_free(error);
            return;
        }
        
        char result_text[MAX_EXPR_LEN];
        snprintf(result_text, sizeof(result_text), "Result: %.2f", result);
        gtk_label_set_text(GTK_LABEL(widgets->result_label), result_text);
    } else {
        // Check if the buffer is exceeded
        size_t current_len = strlen(current_text);
        if (current_len >= MAX_EXPR_LEN - 3) {
            gtk_label_set_text(GTK_LABEL(widgets->result_label),
                             "Error: Expression too long");
            return;
        }
        
        // Add spaces around operators
        if (strchr("+-*/", button_text[0]) != NULL) {
            snprintf(new_text, sizeof(new_text), "%s %s ", current_text, button_text);
        } else {
            snprintf(new_text, sizeof(new_text), "%s%s", current_text, button_text);
        }
        gtk_entry_set_text(GTK_ENTRY(widgets->entry), new_text);
    }
}

static void create_window(void) {
    GtkWidget *window, *grid, *button;
    CalculatorWidgets *widgets = g_new0(CalculatorWidgets, 1);

    // Set up CSS provider
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider, css_data, -1, NULL);
    
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    g_object_unref(provider);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Awsum Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 320, 450);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
    g_signal_connect_swapped(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 8);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    // Create the display entry
    widgets->entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(widgets->entry), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(widgets->entry), 1.0); // Right-align text
    gtk_grid_attach(GTK_GRID(grid), widgets->entry, 0, 0, 4, 1);

    // Result label
    widgets->result_label = gtk_label_new("Result: 0.00");
    gtk_widget_set_halign(widgets->result_label, GTK_ALIGN_END);
    gtk_grid_attach(GTK_GRID(grid), widgets->result_label, 0, 1, 4, 1);

    // Button layout
    const char *button_labels[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+",
        "C"
    };
    
    // Button styles
    const char *button_styles[] = {
        "number", "number", "number", "operator",
        "number", "number", "number", "operator",
        "number", "number", "number", "operator",
        "number", "number", "equal", "operator",
        "clear"
    };
    
    // Create buttons with appropriate styles
    for (int i = 0; i < 16; i++) {
        button = gtk_button_new_with_label(button_labels[i]);
        
        // Add appropriate style class
        GtkStyleContext *context = gtk_widget_get_style_context(button);
        gtk_style_context_add_class(context, button_styles[i]);
        
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), widgets);
        gtk_grid_attach(GTK_GRID(grid), button, i % 4, 2 + i / 4, 1, 1);
    }
    
    // Add clear button with full width
    button = gtk_button_new_with_label("C");
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_class(context, "clear");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), widgets);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 4, 1);
    
    // Memory cleanup
    g_signal_connect_swapped(window, "destroy", G_CALLBACK(g_free), widgets);
    
    // Display the window
    gtk_widget_show_all(window);
}
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    create_window();
    gtk_main();
    return 0;
}
