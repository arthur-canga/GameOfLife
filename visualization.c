//
// Por Arturo Canga. V-25.696.222
// Para AyPII, creado el 13/6/20
//
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libvalidate.h"
#include "functionGeneration.h"
#include "arthurlib.h"

void printinfile(FILE *file, int **matrix, int x, int y){
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            fprintf(file,"%d",matrix[i][j]);
        }
        fprintf(file,"\n");
    }
}

void printinscreen(int **matrix1, int **matrix2, int **matrix3, int x, int y){
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (!matrix1[i][j])
                printf(".");
            else printf("0");
        }
        printf("     ");
        for (int j = 0; j < y; j++) {
            if (!matrix2[i][j])
                printf(".");
            else printf("0");
        }
        printf("     ");
        for (int j = 0; j < y; j++) {
            if (!matrix3[i][j])
                printf(".");
            else printf("0");
        }
        printf("\n");
    }
}



//Nawebona mano, este archivo sólo va a consumir como 4MB de espacio AJSKAJSKASJAKSJAKSJAJSKSJAKSJAK
void show(char *ogfile, int **plana, int **vertical, int **horizontal, const int x, const int y, int time, int iter){
    FILE *planafile, *verticalfile, *horizontalfile;
    char dir[FILENAME_MAX];
    getcwd(dir,FILENAME_MAX);
    char plananame[FILENAME_MAX]="\0";
    char verticalname[FILENAME_MAX]="\0";
    char horizontalname[FILENAME_MAX]="\0";
    strcat(plananame,dir);
    strcat(verticalname,dir);
    strcat(horizontalname,dir);
    strcat(plananame,"/output-matriz-plana-");
    strcat(verticalname,"/output-matriz-vertical-");
    strcat(horizontalname,"/output-matriz-horizontal-");
    strcat(plananame,ogfile);
    strcat(verticalname,ogfile);
    strcat(horizontalname,ogfile);
    strcat(plananame,".txt");
    strcat(verticalname,".txt");
    strcat(horizontalname,".txt");
    planafile = fopen(plananame,"w");
    verticalfile = fopen(verticalname,"w");
    horizontalfile = fopen(horizontalname,"w");
    printf("\e[1;1H\e[2J");
    //Aqui luego hago el llamado a la funcion para la iteracion 0, aka estado inicial
    for (int i = -1; i < iter; i++) {

        //Llamada de limpiado de pantalla. NOTA: CLION NO LO INTERPRETA, EL TERMINAL SI. NO FUNCIONA EN WINDOWS
        printf("\e[1;1H\e[2J");
        if (i>-1) {
            fprintf(planafile, "Iteracion %d\n", i + 1);
            fprintf(verticalfile, "Iteracion %d\n", i + 1);
            fprintf(horizontalfile, "Iteracion %d\n", i + 1);
            printf("Iteración %d\n", i+1);
            fprintf(planafile, "\n");
            fprintf(verticalfile, "\n");
            fprintf(horizontalfile, "\n");
            printf("\n");

        }
        else{
            printf("Iteracion %d (iteración inicial)",i+1);
            printf("\n");
            printf("\n");
        }
        //Imprimimos los títulos con los espacios respectivos
        printf("MATRIZ PLANA     ");
        if (x>17){
            int spaces=x-17;
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
        }
        else printf("     ");
        printf("CONTINUA VERTICAL     ");
        if (x>22){
            int spaces=x-22;
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
        }
        else printf("     ");
        printf("CONTINUA HORIZONTAL\n");
        if (i>-1){
            //Aquí se supone que hacemos los llamados a las 3 funciones generadoras para luego mostrar en pantalla
            automatePlana(plana,x,y);
            automateVert(vertical,x,y);
            automateHorz(horizontal,x,y);
        }
        //Primero escribimos en los archivos
        printinfile(planafile,plana,x,y);
        printinfile(verticalfile,vertical,x,y);
        printinfile(horizontalfile,horizontal,x,y);
        //Ahora se imprime en pantalla, uno al lado del otro
        printinscreen(plana,vertical,horizontal,x,y);
        usleep(time*1000);
    }
    fclose(planafile);
    fclose(verticalfile);
    fclose(horizontalfile);
}
