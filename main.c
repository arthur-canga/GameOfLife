#include <stdio.h>
#include <stdlib.h>
#include "libvalidate.h"
#include "functionGeneration.h"

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
    int **plana=generatematrix(*string,&x,&y);
    int **vertical=generatematrix(*string,&x,&y);
    int **horizontal=generatematrix(*string,&x,&y);

    Generacion_Plana(plana,&x,&y);
    Generacion_Vertical(vertical,&x,&y);
    Generacion_Horizontal(horizontal,&x,&y);
    //El programa compila pero el codigo de retorno del main es un 11, en vez de un 0
    //Aqui resto del programa
    return 0;
}
