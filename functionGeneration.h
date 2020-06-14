//
// Created by luisfer on 13/6/20.
//

#ifndef GAMEOFLIFE_FUNCTIONGENERATION_H
#define GAMEOFLIFE_FUNCTIONGENERATION_H

#endif //GAMEOFLIFE_FUNCTIONGENERATION_H

int VerifCelula(int **content, int beginF, int endF, int beginC, int endC, int x, int y);

int **Create_Plana(int **content, int n, int m);

int **Create_Vert(int **content, int n, int m);

int **Create_Hor(int **content, int n, int m);

int **Generacion_Plana(int **plana, int n, int m);

int **Generacion_Vertical(int **vertical, int n, int m);

int **Generacion_Horitzontal(int **horizontal, int n, int m);

