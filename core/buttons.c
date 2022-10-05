#include "buttons.h"

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