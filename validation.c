//
// Source code de validación
// Arturo Canga. V-25.696.222
// Luis Fernandez. V-
// Para AyPII. Primer Proyecto. Creado el 7/6/20
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Halla el ultimo elemento del arreglo. Usado para la funcion check
int limiter(const char array[]){
    int i=0;
    for (; array[i] ; i++);
    return i;
}

//Lee el archivo y extrae su contenido en una cadena
char *lectura(char *name, int namesize){
    char *aux=(char *)malloc((namesize+4)*sizeof(char));
    strcpy(aux,name);
    strcat(aux,".txt");
    FILE *archivo=fopen(aux,"r");
    if (!archivo){
        fprintf(stderr,"Error de apertura. El archivo no existe");
        exit(0);
    }
    char *content= (char *)malloc(FILENAME_MAX * sizeof(char));
    char buff[FILENAME_MAX];
    int i=0;
    fgets(buff,FILENAME_MAX,archivo);
    while(!feof(archivo)){
        strcat(content,buff);
        i++;
        fgets(buff,FILENAME_MAX,archivo);
    }
    int last=limiter(buff);
    if (buff[last-1]!='\n')
        strcat(content,buff);
    fclose(archivo);
    int contsize=limiter(content);
    content=(char *)realloc(content,contsize);
    return content;
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
        if (corch>2 || corch<0){
            fprintf(stderr,"Error en los corchetes. Muchos corchetes abiertos o desbalanceado");
            exit(1);
        }
    }
    if(corch)
        return 0;
    else return 1;
}

//Chequea que la estructura completa sea válida
int check(const char array[], int limit){
    //Variables dim cuentan las comas dentro de las filas
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
        if ((array[i]=='0' || array[i]=='1') && (array[i+1]!=',' && array[i+1]!='}')){
            printf("Error encontrado en posicion %d. Valor invalido\n", i);
            return 0;
        }
        if(array[i]==','){
            dim++;
            if((array[i-1]!='0' && array[i-1]!='1') && (array[i+1]!='0' && array[i+1]!='1')){
                printf("Error encontrado en posicion %d\n",i);
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
                //Si estoy en un numero y el siguiente no es coma o cierre de corchete...
                if ((array[i]=='0' || array[i]=='1') && (array[i+1]!=',' && array[i+1]!='}')) {
                    printf("Error encontrado en posicion %d. Valor invalido\n", i);
                    return 0;
                }
                //Si la posicion es una coma...
                if(array[i]==','){
                    //Contado auxiliar aumenta
                    dimaux++;
                    //Verificamos que la estructura sea valida y sino return 0
                    if((array[i-1]!='0' && array[i-1]!='1') && (array[i+1]!='0' && array[i+1]!='1')){
                        printf("Error encontrado en posicion %d\n",i);
                        return 0;
                    }
                }
            }
            //Si la dimension del arreglo es distinta a la del primero return 0
            if (dimaux!=dim){
                printf("Error. Dimensiones incorrectas\n");
                return 0;
            }
        }
        //Aumentamos 1 porque caimos en un '}'
        i++;
        dimaux=0;
    }
    return 1;
}

//Verifica si es una fila y si está validada
int esfila(const char s[],int size){
    int corch=0;
    for (int i = 0; i < size; i++) {
        if (s[i]=='{')
            corch++;
        if (s[i]=='}')
            corch--;
        if (corch>1)
            return 0;
    }
    if (s[0]!='{' && s[size-1]!='}')
        return 0;
    for (int i = 1; s[i]!='}' ; i++) {
        if (i%2 && (s[i]!='0' && s[i]!='1'))
            return 0;
        if (!(i%2) && s[i]!=',')
            return 0;
        if (s[size-2]==',')
            return 0;
    }
    return 1;
}

int loner(const char s[], int size){
    if (s[0]=='{' && (s[1]=='0' || s[1]=='1') && s[2]=='}' && size=='4')
        return 1;
    else return 0;
}

//Obtiene la dimensión en X (cantidad de filas)
int getdimX(const char s[], int size){
    int dim=0;
    for (int i = 0; s[i] ; i++) {
        if (s[i]==',' && (s[i-1]=='}' && s[i+1]=='{'))
            dim++;
    }
    return dim+1;
}

//Obtiene la dimensión en Y (casillas de arreglo individual)
int getdimY(const char s[], int size){
    int dim=0;
    for (int i = 0; s[i]!='}' ; i++) {
        if (s[i]==',' && (s[i+1]=='0' || s[i+1]=='1'))
            dim++;
    }
    return dim+1;
}

int **generatematrix(char *string, int *X, int *Y){
    int size=limiter(string);
    *X=getdimX(string,size);
    *Y=getdimY(string,size);
    //Reservamos espacio
    int **matrix=(int **)malloc((*X) * sizeof(int*));
    for (int c = 0; c < *X; c++) {
        matrix[c]=(int *)malloc((*Y) * sizeof(int));
    }
    int j;
    int s=0;
    //for recorre en X el arreglo
    for (int i = 0; i < *X; i++) {
        //Inicializa el contador para recorrer en X
        j=0;
        //for recorre la cadena, variable declarada para guardar el valor
        for (; string[s]!='}'; s++) {
            //Guarda valor si es un 0 o 1. Resta 48 porque obtiene el valor ASCII
            if (string[s]=='0' || string[s]=='1'){
                matrix[i][j]=string[s]-48;
                j++;
            }
        }
        s++;
    }
    return matrix;
}

//Resume el proceso de obtencion de la cadena y de la validacion
char *obtainer(char *s, int size){
    char *fullcontent;
    fullcontent=lectura(s, size);
    eliminarespacios(fullcontent);
    fullcontent=(char *)realloc(fullcontent,limiter(fullcontent)-1);
    if (balanceyvalores(fullcontent)){
        int i=limiter(fullcontent);
        if (!check(fullcontent,i) && !esfila(fullcontent,i) && !loner(fullcontent,i)){
            fprintf(stderr,"Formato invalido. Programa finalizado");
            exit(1);
        }
    }
    else {
        fprintf(stderr,"Formato invalido. Incongruencia de corchetes o caracteres invalidos.\nPrograma finalizado");
        exit(1);
    }
    return fullcontent;
}