//
// Created by luisfer on 13/6/20.
//
#include "functionGeneration.h"

int VerifCelula(int **matriz, int beginF, int endF, int beginC, int endC, int x, int y){
    int r, s, acum=0;
    for (r=beginF;r<=endF;r++){
        for (s=beginC;s<=endC;s++){
            if (r!=x && s!=y) {
                acum = acum + matriz[r][s];
            }
        }
    }
    if (acum==2 || acum==3){
        return 1;
    }
    else{
        return 0;
    }
}
int Verif_Cel_Vert(int **vert, int beginF, int endF, int beginC, int endC, int extre_f, int x, int y){
    int a , b, acum=0;
    for (a=beginF;a<=endF;a++){
        for (b=beginC;b<=endC;b++){
            if (a!=x && b!=y){
                acum = acum + vert[a][b];
            }
        }
    }
    for (b=beginC;b<=endC;b++){
        acum = acum + vert[extre_f][b] ;
    }
    if (acum==2 || acum==3){
        return 1;
    }
    else{
        return 0;
    }
}

int Verif_Cel_Hor(int **hor, int beginF, int endF, int beginC, int endC, int extre_c, int x, int y){
    int a , b, acum=0;
    for (a=beginF;a<=endF;a++){
        for (b=beginC;b<=endC;b++){
            if (a!=x && b!=y){
                acum = acum + hor[a][b];
            }
        }
    }
    for (a=beginC;a<=endC;a++){
        acum = acum + hor[a][extre_c] ;
    }
    if (acum==2 || acum==3){
        return 1;
    }
    else{
        return 0;
    }
}

void Generacion_Plana(int **pla, int n, int m){
    int i, j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (i==0 && j==0){
                pla[i][j] = VerifCelula(pla,i,i+1,j,j+1,i,j);
            }
            else if (i==0 && j==m-1){
                pla[i][j] = VerifCelula(pla,i,j-1,i+1,j,i,j);
            }
            else if (i==n-1 && j==0){
                pla[i][j] = VerifCelula(pla,i-1,i,j,j+1,i,j);
            }
            else if (i==n-1 && j==m-1){
                pla[i][j] = VerifCelula(pla,i-1,i,j-1,j,i,j);
            }
            else if ((i==0) && (j>0 && j<m-1)) {
                pla[i][j] = VerifCelula(pla,i,i+1,j-1,j+1,i,j);
            }
            else if ((i==n-1) && (j>0 && j<m-1)){
                pla[i][j] = VerifCelula(pla,i-1,i,j-1,j+1,i,j);
            }
            else if ((i>0 && i<n-1) && (j==0)){
                pla[i][j] = VerifCelula(pla,i-1,i+1,j,j+1,i,j);
            }
            else if ((i>0 && i<n-1) && (j==m-1)){
                pla[i][j] = VerifCelula(pla,i-1,i+1,j-1,j,i,j);
            }
            else {
                pla[i][j] = VerifCelula(pla,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
}

void Generacion_Vertical(int **vert, int n, int m){
    int i, j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (i==0 && j==0){
                vert[i][j] = Verif_Cel_Vert(vert,i,i+1,j,j+1,n-1,i,j);
            }
            else if (i==0 && j==m-1){
                vert[i][j] = Verif_Cel_Vert(vert,i,i+1,j-1,j,n-1,i,j);
            }
            else if (i==n-1 && j==0){
                vert[i][j] = Verif_Cel_Vert(vert,i-1,i,j,j+1,0,i,j);
            }
            else if (i==n-1 && j==m-1){
                vert[i][j] = Verif_Cel_Vert(vert,i-1,i,j-1,j,0,i,j);
            }
            else if ((i==0) && (j>0 && j<m-1)) {
                vert[i][j] = Verif_Cel_Vert(vert,i,i+1,j-1,j+1,n-1,i,j);
            }
            else if ((i==n-1) && (j>0 && j<m-1)) {
                vert[i][j] = Verif_Cel_Vert(vert, i - 1, i, j - 1, j + 1, 0, i, j);
            }
            else if ((j==0) && (i>0 && i<n-1)){
                vert[i][j] = VerifCelula(vert,i-1,i+1,j,j+1,i,j);
            }
            else if ((j==m-1) && (i>0 && i<n-1)){
                vert[i][j] = VerifCelula(vert,i-1,i+1,j-1,j,i,j);
            }
            else {
                vert[i][j] = VerifCelula(vert,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
}

void Generacion_Horizontal(int **hor, int n, int m){
    int i, j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (i==0 && j==0){
                hor[i][j] = Verif_Cel_Hor(hor,i,i+1,j,j+1,m-1,i,j);
            }
            else if (i==0 && j==m-1){
                hor[i][j] = Verif_Cel_Hor(hor,i,i+1,j-1,j,0,i,j);
            }
            else if (i==n-1 && j==0){
                hor[i][j] = Verif_Cel_Hor(hor,i-1,i,j,j+1,m-1,i,j);
            }
            else if (i==n-1 && j==m-1){
                hor[i][j] = Verif_Cel_Hor(hor,i-1,i,j-1,j,0,i,j);
            }
            else if ((j==0) && (i>0 && i<n-1)) {
                hor[i][j] = Verif_Cel_Hor(hor,i-1,i+1,j,j+1,m-1,i,j);
            }
            else if ((j==m-1) && (i>0 && i<n-1)) {
                hor[i][j] = Verif_Cel_Hor(hor, i - 1, i + 1, j - 1, j , 0, i, j);
            }
            else if ((i==0) && (j>0 && j<m-1)){
                hor[i][j] = VerifCelula(hor,i,i+1,j-1,j+1,i,j);
            }
            else if ((i==n-1) && (j>0 && j<m-1)){
                hor[i][j] = VerifCelula(hor,i-1,i,j-1,j+1,i,j);
            }
            else {
                hor[i][j] = VerifCelula(hor,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
}
