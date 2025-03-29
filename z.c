#include <gtk/gtk.h>

int main(int argc, char** argv){

    gtk_init();

    GtkWidget *window = gtk_window_new();

    gtk_window_set_title (GTK_WINDOW (window), "METANIT.COM");
    gtk_window_present (GTK_WINDOW (window));

    while (g_list_model_get_n_items (gtk_window_get_toplevels ()) > 0)
    g_main_context_iteration (NULL, TRUE);
    return 0;
}