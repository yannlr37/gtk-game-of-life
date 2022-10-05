#ifndef CELL_H
#define CELL_H

typedef struct {
	char* label;
	gboolean state;
	int row;
	int col;
} Cell;

#endif