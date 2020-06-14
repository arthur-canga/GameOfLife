//
// Por Arturo Canga. V-25.696.222
// Para AyPII, creado el 13/6/20
//
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libvalidate.h"

void printinfile(FILE *file, int **matrix, int x, int y){
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            fprintf(file,"%d",matrix[i][j]);
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
    strcat(plananame,"-txt.txt");
    strcat(verticalname,"-txt.txt");
    strcat(horizontalname,"-txt.txt");
    planafile = fopen(plananame,"w");
    verticalfile = fopen(verticalname,"w");
    horizontalfile = fopen(horizontalname,"w");
    //Aqui luego hago el llamado a la funcion para la iteracion 0, aka estado inicial
    for (int i = -1; i < iter; i++) {

        //Llamada de limpiado de pantalla. NOTA: CLION NO LO INTERPRETA, EL TERMINAL SI. NO FUNCIONA EN WINDOWS
        printf("\e[1;1H\e[2J");

        fprintf(planafile,"Iteracion %d\n",i+1);
        fprintf(verticalfile,"Iteracion %d\n",i+1);
        fprintf(horizontalfile,"Iteracion %d\n",i+1);
        fprintf(planafile,"\n");
        fprintf(verticalfile,"\n");
        fprintf(horizontalfile,"\n");
        printf("Iteracion %d",i+1);
        if (i==-1){
            printf(" (iteración inicial)");
        }
        printf("\n");
        //Imprimimos los títulos con los espacios respectivos
        printf(" MATRIZ PLANA      ");
        if (x>17){
            int spaces=x-17;
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
        }
        else printf("     ");
        printf(" CONTINUA VERTICAL      ");
        if (x>22){
            int spaces=x-22;
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
        }
        else printf("     ");
        printf(" CONTINUA HORIZONTAL\n");
        for (int n = 0; n < 3; n++) {
            for (int j = 0; j < x; j++) {
                if (!j)
                    printf("%c",201);
                if (j==x-1)
                    printf("%c",187);
                else printf("%c",205);
            }
            if (n<2)
                printf("     ");
            else printf("\n");
        }
        if (i>-1){
            //Aquí se supone que hacemos los llamados a las 3 funciones generadoras para luego mostrar en pantalla
            printinfile(planafile,plana,x,y);
            printinfile(verticalfile,vertical,x,y);
            printinfile(horizontalfile,horizontal,x,y);
        }
        //Primero escribimos en los archivos
        //Ahora se imprime en pantalla, uno al lado del otro
        //Este for es para la línea
        for (int j = 0; j < y; j++) {
            //Un for pa la primera matriz
            printf("%c",186);
            for (int k = 0; k < x; k++) {
                printf("%d",plana[j][k]);
            }
            printf("%c",186);
            //5 espacios entre matrices
            printf("      ");
            //Un for para la segunda matriz
            printf("%c",186);
            for (int l = 0; l < x; l++) {
                printf("%d",plana[j][l]);
            }
            printf("%c",186);
            //5 espacios
            printf("     ");
            //for para la 3ra matriz
            printf("%c",186);
            for (int m = 0; m < x; m++) {
                printf("%d",plana[j][m]);
            }
            //Salto de linea entre las filas
            printf("%c\n",186);
        }
        //borde bomnito
        printf("%c",200);
        for (int a = 0; a < x; a++) {
            printf("%c",205);
        }
        printf("%c",188);
        usleep(time*1000);
    }
    fclose(planafile);
    fclose(verticalfile);
    fclose(horizontalfile);
}
