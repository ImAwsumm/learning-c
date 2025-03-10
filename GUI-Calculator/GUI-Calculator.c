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
static gboolean validate_input(const char *equation, GError **error) {
    if (!equation || strlen(equation) == 0) {
        // Ah yes, the infamous "calculate nothing" request. Classic...
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
                           "Invalid operator sequence (They're not playing nice together)"); // when an operation can't be completed
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
    if (num_count == 0) {// if there are no numbers
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
        return 0.0;  // Return zero..
      // this is also my faith in voters from the United-States
      // ^^^  (NOT Americans since the term americans implies that the person is from the american continent not the country)
    }

    // Arrays to store our numbers and operators
    double numbers[MAX_EXPR_LEN];
    char operators[MAX_EXPR_LEN];  // I needed help for this part because I was lost and I'm not very good with coding :(
    int num_count = 0, op_count = 0;
    char eq[MAX_EXPR_LEN];
    g_strlcpy(eq, equation, MAX_EXPR_LEN);
    // Time to split this equation
    char *token = strtok(eq, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            char *endptr;
            numbers[num_count] = strtod(token, &endptr);
            if (*endptr != '\0') {  // if the equation doesn't make sense 
                g_set_error(error, g_quark_from_string("CALC_ERROR"), 1,
                           "Invalid number format");
                return 0.0;
            }
            num_count++;
        } else if (strchr("+-*/", token[0]) != NULL) {
            operators[op_count++] = token[0];  // Another operator
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
                              "Division by zero (Nice try, but infinity isn't a number here)");  // prevents divisions by zero because ... I think it's pretty obvious ...
                    return 0.0;
                }
                numbers[i] /= numbers[i + 1]; // the division
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
            result += numbers[i + 1];  // The additions
        } else if (operators[i] == '-') {
            result -= numbers[i + 1];  // Subtracting
        }
    }
    return result;
}
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    CalculatorWidgets *widgets = (CalculatorWidgets *)data;
    const char *button_text = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(widgets->entry));
    // Make the "C" button actually clear everything and set the equation to 0
    char new_text[MAX_EXPR_LEN];
    if (strcmp(button_text, "C") == 0) {
        // Clear everything. Because you asked for it 
        gtk_entry_set_text(GTK_ENTRY(widgets->entry), "");
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "Result: ");  // sets the result to nothing DO NOT remove the Result: 
                                                                           // since this is before the result as a sign for the user
    } else if (strcmp(button_text, "=") == 0) {
        // Time to calculate!
        GError *error = NULL;
        
        // Check if the input is empty first
        if (strlen(current_text) == 0) {
            gtk_label_set_text(GTK_LABEL(widgets->result_label), "Error: No expression entered");
            return;  // Stop further processing because you wanna save power
        }
        double result = calculate(current_text, &error);

        // Associates the given error with the right error message
        if (error != NULL) {
            gtk_label_set_text(GTK_LABEL(widgets->result_label), error->message);
            g_error_free(error);
            return;
        }
        char result_text[MAX_EXPR_LEN];
        snprintf(result_text, sizeof(result_text), "Result: %.2f", result);
        gtk_label_set_text(GTK_LABEL(widgets->result_label), result_text);
    } else {

        // Check if the buffer is exeeded
        size_t current_len = strlen(current_text);
        if (current_len >= MAX_EXPR_LEN - 3) {
            gtk_label_set_text(GTK_LABEL(widgets->result_label),
                             "Error: Expression too long (Your computer sucks haha!n])");
            return;
        }
        // Add spaces
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

    // Make a window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Awsum Calculator");  // Not just any calculator, the AWSUM calculator!!
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 500); // weird resolution more on line 189
    g_signal_connect_swapped(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  //You can change the resolution I guess
  //I usually use 1080p but since this is a calculator idk..

    // Create a grid in order to add the buttons later
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5); // smaller spacing
    gtk_container_set_border_width(GTK_CONTAINER(grid), 10);  // Border padding because it looks Awsum

    // Create the input field
    widgets->entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(widgets->entry), FALSE); //read only because you can mess stuff up...
    gtk_grid_attach(GTK_GRID(grid), widgets->entry, 0, 0, 4, 1);

    // Label to show results
    widgets->result_label = gtk_label_new("Result: ");
    gtk_grid_attach(GTK_GRID(grid), widgets->result_label, 0, 1, 4, 1);

    // Button layout arranged like a phone keypad
    // Because who doesn't love a classic design that works very well and very fast
    const char *button_labels[] = {
        "7", "8", "9", "/",  // some numbers I guess...
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+",
        "C"                  // The "mistake" button

// Adding a second layout as an option may be a future plan idk...
    };
    // Create buttons
    for (int i = 0; i < 17; i++) {
        button = gtk_button_new_with_label(button_labels[i]);
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), widgets);
        if (i == 16) {
            // The clear button is different because...      Yes.
            gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 4, 1);
        } else {
            gtk_grid_attach(GTK_GRID(grid), button, i % 4, 2 + i / 4, 1, 1); // everything goes in the grid nothing outside.
// assign every button to it's right value (integer)
        }
    }
    // Clear the window 
    g_signal_connect_swapped(window, "destroy", G_CALLBACK(g_free), widgets);
    // Display the window
    gtk_widget_show_all(window);
}
// The main function
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);  // Wake up GTK
    create_window();
    gtk_main();             // Keep the party going until someone clicks the X and closes this :(
    return 0;
// this is only going public once this is polished and I am happy with the result
}
