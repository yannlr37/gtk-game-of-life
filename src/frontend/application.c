#include "application.h"

void app_run()
{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *valign;
	GtkWidget *separator;
	GtkWidget *buttons;

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
}

GtkWidget *sd_make_game_grid()
{
	GtkWidget *hbox;
	GtkWidget *grid;

	hbox = gtk_hbox_new(TRUE, 0);

	grid = gtk_table_new(3, 3, TRUE);

	GtkWidget *cells[5][5];

	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
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