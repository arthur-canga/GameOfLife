#include <stdio.h>
#include <string.h>
#include <unistd.h>


//Lee el archivo y extrae su contenido en una cadena
char *lectura(char *name){
    char dir[FILENAME_MAX];
    getcwd(dir,FILENAME_MAX);
    char fulldir[FILENAME_MAX]="\0";
    strcat(fulldir,dir);
    strcat(fulldir,"/");
    strcat(fulldir,name);
    FILE *archivo=fopen(fulldir,"r");
    if (!archivo){
        printf("Error de apertura. El archivo no existe");
        return NULL;
    }
    static char test[FILENAME_MAX];
    char buff[FILENAME_MAX];
    while(!feof(archivo)){
        fgets(buff,FILENAME_MAX,archivo);
        strcat(test,buff);
    }
    return test;
}


//Elimina los espacios y saltos de linea
void eliminarespacios(char *s){
    const char* d = s;
    do {
        while (*d == ' ' || *d == '\n') {
            ++d;
        }
    } while ((*s++ = *d++));
}

//Verifica que cada caracter de la cadena sea valido y que los corchetes esten balanceados
int balanceyvalores(const char *s){
    int corch=0;
    while(*s!='\0'){
        if(*s=='{')
            corch++;
        if (*s=='}')
            corch--;
        if(*s!='0' && *s!='1' && *s!=',' && *s!='{' && *s!='}')
            return 0;
        s++;
    }
    if(corch)
        return 0;
    else return 1;
}

//Halla el ultimo elemento del arreglo. Usado para la funcion check
int limiter(const char array[]){
    int i=0;
    for (; array[i] ; i++);
    return i;
}

//Chequea que la fila sea valida

int check(const char array[], int limit){
    int dim=0;
    int dimaux=0;
    int i=2;

    //Chequeo de apertura
    if(array[0]!='{' && array[1]!='{')
        return 0;
    if(array[2]!='0' && array[2]!='1')
        return 0;
    if(array[limit-1]!='}' && array[limit-2]!='}')
        return 0;

    //Chequeo de primera fila y calculo de dimension
    for (; array[i]!='}' ; i++) {
        if(array[i]==','){
            dim++;
            if((array[i-1]!='0' && array[i-1]!='1') && (array[i+1]!='0' && array[i+1]!='1')){
                printf("Error found on %d\n",i);
                return 0;
            }
        }
    }
    while(i!=limit){
        //Luego de la primera fila, debe ir una comma
        if(array[i]==','){
            //Si es una coma, aumentamos el contador
            i++;
            //Empezamos a leer el siguiente arreglo
            for ( ; array[i]!='}' ; i++) {
                //Si la posicion es una coma...
                if(array[i]==','){
                    //Contado auxiliar aumenta
                    dimaux++;
                    //Verificamos que la estructura sea valida y si no es return 0
                    if((array[i-1]!='0' && array[i-1]!='1') && (array[i+1]!='0' && array[i+1]!='1')){
                        printf("Error found on %d\n",i);
                        return 0;
                    }
                }
            }
            //Si la dimension del arreglo es distinta a la del primero return 0
            if (dimaux!=dim){
                printf("Error found. Wrong dimentions\n");
                return 0;
            }
        }
        //Aumentamos 1 porque caimos en un '}'
        i++;
        dimaux=0;
    }
    return 1;
}


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
    printf("%s\n",array);
    return 0;
}
