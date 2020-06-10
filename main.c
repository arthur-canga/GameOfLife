#include <stdio.h>
#include "libvalidate.h"

//Estructura de la validacion
//1. Convertir archivo a string - DONE
//2. Eliminar espacios y saltos de linea - DONE
//3. Validar - WIP
//4. Convertir string a arreglo

//Prueba 1: leer un archivo de texto cualquiera, probar eliminarespacios y limiter. Correcto!
//Prueba 2: introducir una cadena de arreglos de igual dimension, pasarle eliminarespacios, balanceyvalores, limiter
//          y check. Correcto!
//Prueba 3:
int main() {
    char *array;
    array=lectura("prueba.txt");
    eliminarespacios(array);
    int i;
    if(balanceyvalores(array)){
        i=limiter(array);
        printf("%d\n",check(array,i));
    }
    return 0;
}
