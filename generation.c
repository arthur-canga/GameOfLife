//
// Source code de generación celular
// Arturo Canga. V-25.696.222
// Luis Fernandez. V-
// Para AyPII. Primer proyecto. Creado el 14/6/20
//

#include <stdlib.h>

//n-m posicion actual
//x-y dimension total

//MIN VECINOS 3
void checkplana(int **matrix, int **aux, int n, int m, int x, int y) {
    int vecinos = 0;

    if (x==1 && y==1){
        vecinos=0;
    } else if (y == 1 && x > 1) {
    //Matriz columna

        //No es borde
        if (n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }
        //Borde superior
        if (!n) {
            if (matrix[n + 1][m])
                vecinos++;
        }
        if (n == (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
        }
    } else if (x == 1 && y > 1) {
        //Matriz fila

        //No es borde
        if (m > 0 && m < (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }
        //Borde superior
        if (!m) {
            if (matrix[n][m - 1])
                vecinos++;
        }
        if (m == (x - 1)) {
            if (matrix[n][m + 1])
                vecinos++;
        }
    } else {
        //Si no es borde ni esquina
        if (n > 0 && m > 0 && n < (x - 1) && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }

        //BORDES
        //Si es borde superior y no es esquina
        if (!n && m > 0 && m < (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Si es borde inferior y no es esquina
        if (n == (x - 1) && m > 0 && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }
        //Si es borde izquierdo y no es esquina
        if (!m && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Si es borde derecho y no es esquina
        if (m == (y - 1) && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }

        //ESQUINAS
        //Sup izq
        if (!n && !m) {
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Inf der
        if (n == (x - 1) && m == (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
        }
        //Sup der
        if (!n && m == (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }
        //Inf izq
        if (n == (x - 1) && !m) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }

    }
        //CAMBIO DE LA CELULA
        if (matrix[n][m] && (vecinos == 2 || vecinos == 3))
            aux[n][m] = 1;
        if (matrix[n][m] && (vecinos < 2 || vecinos > 3))
            aux[n][m] = 0;
        if (!matrix[n][m] && vecinos == 3)
            aux[n][m] = 1;
}

//MIN VECINOS: 5
void checkvertical(int **matrix, int **aux, int n, int m, int x, int y) {
    int vecinos = 0;

    if (x==1 && y==1){
        if (matrix[n][m])
            vecinos=2;
        else vecinos=0;
    } else if (y == 1 && x > 1) {
    //Matriz columna

        //No es borde
        if (n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }
        //Borde superior
        if (!n) {
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[x - 1][m])
                vecinos++;
        }
        //Borde inferior
        if (n == (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[0][m])
                vecinos++;
        }
    }else if (x == 1 && y > 1) {
        //Matriz fila

        //No es borde
        if (m > 0 && m < (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }
        //Borde superior
        if (!m) {
            if (matrix[n][m - 1])
                vecinos++;
        }
        if (m == (x - 1)) {
            if (matrix[n][m + 1])
                vecinos++;
        }
    } else {
        //Si no es borde ni esquina
        if (n > 0 && m > 0 && n < (x - 1) && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //BORDES
        //Borde superior no esquina
        if (!n && m > 0 && m < (y - 1)) {
            if (matrix[x - 1][m - 1])
                vecinos++;
            if (matrix[x - 1][m])
                vecinos++;
            if (matrix[x - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }

        //Borde inferior no esquina
        if (n == (x - 1) && m > 0 && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[0][m - 1])
                vecinos++;
            if (matrix[0][m])
                vecinos++;
            if (matrix[0][m + 1])
                vecinos++;
        }

        //Borde izquierdo y no es esquina
        if (!m && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }

        //Borde derecho y no es esquina
        if (m == (y - 1) && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }

        //ESQUINAS
        //Sup izq
        if (!n && !m) {
            if (matrix[x - 1][m])
                vecinos++;
            if (matrix[x - 1][m + 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Sup der
        if (!n && m == (y - 1)) {
            if (matrix[x - 1][m - 1])
                vecinos++;
            if (matrix[x - 1][m])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }
        //Inf izq
        if (n == (x - 1) && !m) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[0][m])
                vecinos++;
            if (matrix[0][m + 1])
                vecinos++;
        }
        //Inf der
        if (n == (x - 1) && m == (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[0][m - 1])
                vecinos++;
            if (matrix[0][m])
                vecinos++;
        }
    }
    //CAMBIO DE LA CELULA
    if (matrix[n][m] && (vecinos == 2 || vecinos == 3))
        aux[n][m] = 1;
    if (matrix[n][m] && (vecinos < 2 || vecinos > 3))
        aux[n][m] = 0;
    if (!matrix[n][m] && vecinos == 3)
        aux[n][m] = 1;
}

//MIN VECINOS 5
void checkhorizontal(int **matrix, int **aux, int n, int m, int x, int y) {
    int vecinos = 0;
    if (x==1 && y==1){
        if (matrix[n][m])
            vecinos=2;
        else vecinos=0;
    } else if (y == 1 && x > 1) {
    //Matriz columna

        //No es borde
        if (n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
        }
        //Borde superior
        if (!n) {
            if (matrix[n + 1][m])
                vecinos++;
        }
        if (n == (x - 1)) {
            if (matrix[n - 1][m])
                vecinos++;
        }
    }else if (x == 1 && y > 1) {
        //Matriz fila

        //No es borde
        if (m > 0 && m < (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }
        //Borde izquierdo
        if (!m) {
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n][y - 1])
                vecinos++;
        }
        if (m == (x - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][0])
                vecinos++;
        }
    } else {
        //Si no es borde ni esquina
        if (n > 0 && m > 0 && n < (x - 1) && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }

        //BORDES
        //Borde izquierdo y no esquina
        if (!m && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][y - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][y - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][y - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Borde derecho y no esquina
        if (m == (y - 1) && n > 0 && n < (x - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][0])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][0])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][0])
                vecinos++;
        }
        //Borde superior y no esquina
        if (!n && m > 0 && m < (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Borde inferior y no esquina
        if (n == (x - 1) && m > 0 && m < (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }

        //ESQUINAS
        //Sup izq
        if (!n && !m) {
            if (matrix[n][y - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
            if (matrix[n + 1][y - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][m + 1])
                vecinos++;
        }
        //Sup der
        if (!n && m == (y - 1)) {
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][0])
                vecinos++;
            if (matrix[n + 1][m - 1])
                vecinos++;
            if (matrix[n + 1][m])
                vecinos++;
            if (matrix[n + 1][0])
                vecinos++;
        }
        //Inf izq
        if (n == (x - 1) && !m) {
            if (matrix[n - 1][y - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][m + 1])
                vecinos++;
            if (matrix[n][y - 1])
                vecinos++;
            if (matrix[n][m + 1])
                vecinos++;
        }
        //Inf der
        if (n == (x - 1) && m == (y - 1)) {
            if (matrix[n - 1][m - 1])
                vecinos++;
            if (matrix[n - 1][m])
                vecinos++;
            if (matrix[n - 1][0])
                vecinos++;
            if (matrix[n][m - 1])
                vecinos++;
            if (matrix[n][0])
                vecinos++;
        }
    }
    //CAMBIO DE LA CELULA
    if (matrix[n][m] && (vecinos == 2 || vecinos == 3))
        aux[n][m] = 1;
    if (matrix[n][m] && (vecinos < 2 || vecinos > 3))
        aux[n][m] = 0;
    if (!matrix[n][m] && vecinos == 3)
        aux[n][m] = 1;
}

void clone(int **a, int **b, int x, int y){
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            b[i][j]=a[i][j];
        }
    }
}

void automatePlana(int **matriz, int x, int y){
    int **aux=(int **)malloc(x*sizeof(int*));
    for (int a = 0; a < x; a++) {
        aux[a] = (int *) malloc(y * sizeof(int));
    }
    clone(matriz,aux,x,y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            checkplana(matriz,aux,i,j,x,y);
        }
    }
    clone(aux,matriz,x,y);
    free(aux);
}

void automateVert(int **matriz, int x, int y){
    int **aux=(int **)malloc(x*sizeof(int*));
    for (int a = 0; a < x; a++) {
        aux[a] = (int *) malloc(y * sizeof(int));
    }
    clone(matriz,aux,x,y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            checkvertical(matriz,aux,i,j,x,y);
        }
    }
    clone(aux,matriz,x,y);
    free(aux);
}

void automateHorz(int **matriz, int x, int y){
    int **aux=(int **)malloc(x*sizeof(int*));
    for (int a = 0; a < x; a++) {
        aux[a] = (int *) malloc(y * sizeof(int));
    }
    clone(matriz,aux,x,y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            checkhorizontal(matriz,aux,i,j,x,y);
        }
    }
    clone(aux,matriz,x,y);
    free(aux);
}