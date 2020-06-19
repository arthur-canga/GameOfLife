//
// Por Arturo Canga. V-25.696.222
// Para AyPII, creado el 13/6/20
//
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void printinfile(FILE *file, int **matrix, int x, int y);

void show(char *ogfile, int ogsize, int **plana, int **vertical, int **horizontal, int x, int y, int time, int iter);