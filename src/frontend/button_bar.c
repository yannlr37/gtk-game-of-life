#include "button_bar.h"
#include "button_callbacks.h"

GtkWidget *sd_make_button_actions()
{
	GtkWidget *start;
	GtkWidget *stop;
	GtkWidget *reset;
	GtkWidget *hbox;

	hbox = gtk_hbox_new(FALSE, 4);

	start = sd_make_icon_button("icons/play.png");
	gtk_widget_set_tooltip_text(start, "start game");
	g_signal_connect (G_OBJECT (start), "button_press_event", G_CALLBACK (startGame), (gpointer) "Start");

	stop = sd_make_icon_button("icons/pause.png");
	gtk_widget_set_tooltip_text(stop, "stop game process");
	g_signal_connect (G_OBJECT (stop), "button_press_event", G_CALLBACK (stopGame), (gpointer) "Stop");

	reset = gtk_button_new_with_label("Reset");
	gtk_widget_set_tooltip_text(reset, "start game");
	g_signal_connect (G_OBJECT (reset), "button_press_event", G_CALLBACK (resetGame), (gpointer) "Reset");

	gtk_box_pack_end(GTK_BOX (hbox), start, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX (hbox), stop, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX (hbox), reset, FALSE, FALSE, 0);

	return hbox;
}