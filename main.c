#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

int main() {
    char *array;
    array=lectura("prueba.txt");
    printf("%s",array);
    return 0;
}
