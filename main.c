#include <stdio.h>
#include <stdlib.h>
#include "libvalidate.h"

//Validacion finalizada
//TODO generacion celular
//TODO refresh de pantalla
//TODO representacion triple matricial

//Variable content=matriz principal
//Variables X y Y representan la cantidad de filas y columnas.
int main() {
    char *string;
    char *name=(char *)malloc(FILENAME_MAX*sizeof(char ));
    int i,t;
    printf("Introduzca el nombre del archivo (sin su extensión de archivo): ");
    scanf("%s",name);
    printf("Introduzca la cantidad de iteraciones que quiere generar: ");
    scanf("%d",&i);
    printf("Introduzca el tiempo entre iteraciones (en milisegundos): ");
    scanf("%d",&t);
    string=obtainer(name);
    free(name);
    int x;
    int y;
    int **content=generatematrix(string,&x,&y);
    free(string);
    //Aqui resto del programa
    return 0;
}
