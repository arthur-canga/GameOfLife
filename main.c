#include <stdio.h>
#include <stdlib.h>
#include "libvalidate.h"
#include "functionGeneration.h"
#include "libvisual.h"
#include "arthurlib.h"

//Validacion finalizada
//Proyecto casi terminado
//TODO arreglar el error del al liberar la variable string PRIORITARIO
//TODO arreglar los títulos de las matrices
//TODO espaciados entre matrices y títulos en los archivos
//TODO arreglar comentarios y cambiar el nombre a los archivos
//TODO arreglar cabeceras de archivos para que aparezcan los dos nombres

//Variable content=matriz principal
//Variables X y Y representan la cantidad de filas y columnas.
int main() {
    char *name=(char *)malloc(FILENAME_MAX*sizeof(char ));
    int n,t;
    printf("Introduzca el nombre del archivo (sin su extensión de archivo): ");
    scanf("%s",name);
    printf("Introduzca la cantidad de iteraciones que quiere generar: ");
    scanf("%d",&n);
    printf("Introduzca el tiempo entre iteraciones (en milisegundos): ");
    scanf("%d",&t);
    char *string=obtainer(name);
    int x;
    int y;
    int **plana=generatematrix(string,&x,&y);
    int **vertical=generatematrix(string,&x,&y);
    int **horizontal=generatematrix(string,&x,&y);
    free(string);
    show(name,plana,vertical,horizontal,x,y,t,n);
    return 0;
}
