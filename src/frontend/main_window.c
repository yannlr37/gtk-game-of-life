#include "main_window.h"

GtkWidget *sd_init_main_window()
{
	GtkWidget *window;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Game of Life");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 0);
	gtk_window_set_resizable(window, FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 12);

	return window;
}
