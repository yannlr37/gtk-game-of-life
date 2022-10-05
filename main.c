#include <gtk/gtk.h>
#include "src/style.h"
#include "src/button_callbacks.h"
#include "src/cell.h"

GtkWidget *sd_make_icon_button(gchar *iconFilename)
{
	GtkWidget *button;
	GtkWidget *box;
	GtkWidget *icon;
	
	button = gtk_button_new();

	box = gtk_hbox_new(TRUE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(box), 2);

	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(iconFilename, &error);
	if (pixbuf == NULL) {
		g_message("%s", error->message);
	}
	pixbuf = gdk_pixbuf_scale_simple(pixbuf, 12, 12, GDK_INTERP_BILINEAR);
	icon = gtk_image_new_from_pixbuf( gdk_pixbuf_copy(pixbuf) );
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(button), box);

	return button;
}

GtkWidget *sd_make_icon_button_with_label(gchar *iconFilename, gchar *labelText)
{
	GtkWidget *button;
	GtkWidget *box;
	GtkWidget *icon;
	GtkWidget *label;
	
	button = gtk_button_new();

	box = gtk_hbox_new(TRUE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(box), 2);

	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(iconFilename, &error);
	if (pixbuf == NULL) {
		g_message("%s", error->message);
	}
	pixbuf = gdk_pixbuf_scale_simple(pixbuf, 12, 12, GDK_INTERP_BILINEAR);
	icon = gtk_image_new_from_pixbuf( gdk_pixbuf_copy(pixbuf) );
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);

	label = gtk_label_new(labelText);
	
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 2);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 2);

	gtk_container_add(GTK_CONTAINER(button), box);

	return button;
}

GtkWidget *sd_make_button_actions()
{
	GtkWidget *startBtn;
	GtkWidget *stopBtn;
	GtkWidget *resetBtn;
	GtkWidget *hbox;

	hbox = gtk_hbox_new(FALSE, 4);

	startBtn = sd_make_icon_button("icons/play.png");
	gtk_widget_set_tooltip_text(startBtn, "start game");
	g_signal_connect (G_OBJECT (startBtn), "button_press_event", G_CALLBACK (startGame), (gpointer) "Start");

	stopBtn = sd_make_icon_button("icons/pause.png");
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

	grid = gtk_table_new(3, 3, TRUE);

	GtkWidget *cells[5][5];

	for (int i=0; i<GRID_SIZE; i++) {
		for (int j=0; j<GRID_SIZE; j++) {
			Cell cell;
			cell.label = "Cell";
			cell.state = FALSE;
			cell.row = 0+j;
			cell.col = 0+i;
			cells[i][j] = gtk_button_new_with_label(cell.label);	
			g_signal_connect (
				G_OBJECT (cells[i][j]), 
				"button_press_event", 
				G_CALLBACK (displayState), 
				(gpointer) cell.state
			);
			gtk_table_attach_defaults(
				grid, 
				cells[i][j], 
				cell.col, 
				cell.col + 1, 
				cell.row, 
				cell.row + 1
			);
		}	
	}
	
	//grid = gtk_text_view_new();

	gtk_box_pack_start(GTK_BOX (hbox), grid, TRUE, TRUE, 0);

	return hbox;
}

GtkWidget *sd_init_main_window()
{
	GtkWidget *window;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Game of Life");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 0);
	gtk_window_set_resizable(window, FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window), MIN_BORDER_WIDTH);

	return window;
}

int main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *valign;
	GtkWidget *separator;
	GtkWidget *buttons;

	gtk_init(&argc, &argv);

	window = sd_init_main_window();

	valign = gtk_vbox_new(FALSE, 4);

	separator = gtk_hseparator_new();

	grid = sd_make_game_grid();
	gtk_container_add(GTK_CONTAINER(valign), grid);
	gtk_container_add(GTK_CONTAINER(valign), separator);

	buttons = sd_make_button_actions();
	gtk_container_add(GTK_CONTAINER(valign), buttons);

	gtk_container_add(GTK_CONTAINER(window), valign);

	gtk_widget_show_all(window);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_main();

	return 0;
}