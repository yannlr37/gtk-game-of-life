#ifndef BUTTON_CALLBACKS_H
#define BUTTON_CALLBACKS_H

#include <gtk/gtk.h>

void startGame(GtkWidget *widget, GdkEventButton *event, gpointer data );

void stopGame(GtkWidget *widget, GdkEventButton *event, gpointer data );

void resetGame(GtkWidget *widget, GdkEventButton *event, gpointer data );

void displayState(GtkWidget *widget, GdkEventButton *event, gpointer data );

#endif