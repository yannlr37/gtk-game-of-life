#include <gtk/gtk.h>
#include "src/style.h"
#include "src/button_callbacks.h"

GtkWidget *sd_make_button_actions()
{
	GtkWidget *startBtn;
	GtkWidget *stopBtn;
	GtkWidget *resetBtn;
	GtkWidget *hbox;

	hbox = gtk_hbox_new(FALSE, 4);

	startBtn = gtk_button_new_with_label("Start");
	gtk_widget_set_tooltip_text(startBtn, "start game");
	g_signal_connect (G_OBJECT (startBtn), "button_press_event", G_CALLBACK (startGame), (gpointer) "Start");

	stopBtn = gtk_button_new_with_label("Stop");
	gtk_widget_set_tooltip_text(stopBtn, "stop game process");
	g_signal_connect (G_OBJECT (stopBtn), "button_press_event", G_CALLBACK (stopGame), (gpointer) "Stop");

	resetBtn = gtk_button_new_with_label("Reset");
	gtk_widget_set_tooltip_text(resetBtn, "start game");
	g_signal_connect (G_OBJECT (resetBtn), "button_press_event", G_CALLBACK (resetGame), (gpointer) "Reset");

	gtk_box_pack_end(GTK_BOX (hbox), startBtn, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX (hbox), stopBtn, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX (hbox), resetBtn, FALSE, FALSE, 0);

	return hbox;
}

GtkWidget *sd_make_game_grid()
{
	GtkWidget *hbox;
	GtkWidget *grid;

	hbox = gtk_hbox_new(TRUE, 0);

	grid = gtk_button_new_with_label("Grid");
	gtk_box_pack_start(GTK_BOX (hbox), grid, TRUE, TRUE, 0);

	return hbox;
}

GtkWidget *sd_init_main_window()
{
	GtkWidget *window;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Game of Life");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 0);
	gtk_container_set_border_width(GTK_CONTAINER(window), MIN_BORDER_WIDTH);

	return window;
}

int main (int argc, char *argv[])
{
	GtkWidget *window;
	//GtkWidget *grid;
	GtkWidget *valign;
	GtkWidget *buttons;

	gtk_init(&argc, &argv);

	window = sd_init_main_window();

	valign = gtk_vbox_new(FALSE, 4);

	//grid = sd_make_game_grid();
	//gtk_container_add(GTK_CONTAINER(valign), grid);

	buttons = sd_make_button_actions();
	gtk_container_add(GTK_CONTAINER(valign), buttons);

	gtk_container_add(GTK_CONTAINER(window), valign);

	gtk_widget_show_all(window);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_main();

	return 0;
}