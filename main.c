#include <gtk/gtk.h>
#include "src/frontend/application.h"

int main (int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	app_run();
	gtk_main();

	return 0;
}