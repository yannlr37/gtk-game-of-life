#ifndef BUTTONS_H
#define BUTTONS_H

#include <gtk/gtk.h>

GtkWidget *sd_make_icon_button(gchar *iconFilename);
GtkWidget *sd_make_icon_button_with_label(gchar *iconFilename, gchar *labelText);

#endif