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
