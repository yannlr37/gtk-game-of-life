#include <gtk/gtk.h>
#include "button_callbacks.h"

void startGame(GtkWidget *widget, GdkEventButton *event, gpointer data )
{
	g_print("%s game !\n", (gchar *) data);
}

void stopGame(GtkWidget *widget, GdkEventButton *event, gpointer data )
{
	g_print("%s game !\n", (gchar *) data);
}

void resetGame(GtkWidget *widget, GdkEventButton *event, gpointer data )
{
	g_print("%s game !\n", (gchar *) data);
}