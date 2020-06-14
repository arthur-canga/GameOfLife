//
// Created by luisfer on 13/6/20.
//
#include "functionGeneration.h"

int VerifCelula(int **content, int beginF, int endF, int beginC, int endC, int x, int y){
    int r, s, acum=0;
    for (r=beginF;r<=endF;r++){
        for (s=beginC;s<=endC;s++){
            if (r!=x && s!=y) {
                acum = acum + content[r][s];
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
int **Create_Plana(int **content, int n, int m){
    int plana[n][m];
    int i, j;

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            plana[i][j] = content[i][j];
        }
    }
    return plana;
}
int **Create_Vert(int **content, int n, int m){
    int vertical[n+2][m];
    int i, j, z=n+2;
    for (i=1; i<n ; i++){
        for (j=1; j<m ; j++){
            vertical[i][j] = content[i][j];
        }
    }
    for (i=0; i<m ; i++) {
        vertical[0][i] = content[n-1][i];
    }
    for (i=0; i<m ; i++) {
        vertical[z-1][i] = content[0][i];
    }
    return vertical ;
}
int **Create_Hor(int **content, int n, int m){
    int horizontal[n][m+2];
    int i, j, z=m+2;
    for (i=1; i<n ; i++){
        for (j=1; j<m ; j++){
            horizontal[i][j] = content[i][j];
        }
    }
    for (i=0; i<n ; i++) {
        horizontal[i][0] = content[i][m-1];
    }
    for (i=0; i<n ; i++) {
        horizontal[i][z-1] = content[i][0];
    }
    return horizontal ;
}

int **Generacion_Plana(int **plana, int n, int m){
    int i, j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (i==0 && j==0){
                plana[i][j] = VerifCelula(**plana,i,i+1,j,j+1,i,j);
            }
            else if (i==0 && j==m-1){
                plana[i][j] = VerifCelula(**plana,i,i+1,j-1,j,i,j);
            }
            else if (i==n-1 && j==0){
                plana[i][j] = VerifCelula(**plana,i-1,i,j,j+1,i,j);
            }
            else if (i==n-1 && j==m-1){
                plana[i][j] = VerifCelula(**plana,i-1,i,j-1,j,i,j);
            }
            else if ((i==0) && (j!=0 || j!=m-1)) {
                plana[i][j] = VerifCelula(**plana,i,i+1,j-1,j+1,i,j);
            }
            else if ((i==n-1) && (j!=0 || j!=m-1)){
                plana[i][j] = VerifCelula(**plana,i,i-1,j-1,j+1,i,j);
            }
            else if ((i!=0 || i!=n-1) && (j==0)){
                plana[i][j] = VerifCelula(**plana,i-1,i+1,j,j+1,i,j);
            }
            else if ((i!=0 || i!=n-1) && (j==m-1)){
                plana[i][j] = VerifCelula(**plana,i-1,i+1,j-1,j,i,j);
            }
            else {
                plana[i][j] = VerifCelula(**plana,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
    return plana;
}

int **Generacion_Vertical(int **vertical, int n, int m){
    int i, j;
    for (i=1;i<n;i++){
        for (j=0;j<m;j++){
            if ((i!=0 || i!=n-1) && (j==0)){
                vertical[i][j] = VerifCelula(**vertical,i-1,i+1,j,j+1,i,j);
            }
            else if ((i!=0 || i!=n-1) && (j==m-1)){
                vertical[i][j] = VerifCelula(**vertical,i-1,i+1,j-1,j,i,j);
            }
            else {
                vertical[i][j] = VerifCelula(**vertical,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
    return vertical;
}

int **Generacion_Horitzontal(int **horizontal, int n, int m){
    int i, j;
    for (i=1;i<n;i++){
        for (j=0;j<m;j++){
            if ((i==0) && (j!=0 || j!=m-1)){
                horizontal[i][j] = VerifCelula(**horizontal,i-1,i+1,j,j+1,i,j);
            }
            else if ((i==n-1) && (j!=0 || j!=m-1)){
                horizontal[i][j] = VerifCelula(**horizontal,i-1,i+1,j-1,j,i,j);
            }
            else {
                horizontal[i][j] = VerifCelula(**horizontal,i-1,i+1,j-1,j+1,i,j);
            }
        }
    }
    return horizontal;
}
