#include <stdio.h>
#include <stdlib.h>
#include "libvalidate.h"
#include "libvisual.h"
#include "libgenerate.h"


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
