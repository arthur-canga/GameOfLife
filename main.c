//
// Código principal
// Arturo Canga. V-25.696.222
// Luis Fernandez. V-28.002.235
// Para AyPII. Primer proyecto. Creado el 7/6/20
//

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
    int namesize=limiter(name);
    name=(char *)realloc(name,namesize+1);
    char *string=obtainer(name,namesize);
    printf("Introduzca la cantidad de iteraciones que quiere generar: ");
    scanf("%d",&n);
    printf("Introduzca el tiempo entre iteraciones (en milisegundos): ");
    scanf("%d",&t);
    int x;
    int y;
    int **plana=generatematrix(string,&x,&y);
    int **vertical=generatematrix(string,&x,&y);
    int **horizontal=generatematrix(string,&x,&y);
    free(string);
    show(name,namesize,plana,vertical,horizontal,x,y,t,n);
    free(name);
    return 0;
}
