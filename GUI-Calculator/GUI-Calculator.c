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
