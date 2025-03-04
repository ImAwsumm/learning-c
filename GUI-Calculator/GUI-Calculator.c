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

//
