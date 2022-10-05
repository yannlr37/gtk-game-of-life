#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtk/gtk.h>
#include "button_bar.h"
#include "main_window.h"
#include "button_callbacks.h"
#include "../backend/cell.h"

void app_run();
GtkWidget *sd_make_game_grid();

#endif