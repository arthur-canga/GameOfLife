//
// Created by luisfer on 13/6/20.
//

#ifndef GAMEOFLIFE_FUNCTIONGENERATION_H
#define GAMEOFLIFE_FUNCTIONGENERATION_H

#endif //GAMEOFLIFE_FUNCTIONGENERATION_H

int VerifCelula(int **content, int beginF, int endF, int beginC, int endC, int x, int y);

int Verif_Cel_Vert(int **vert, int beginF, int endF, int beginC, int endC, int extre_f, int x, int y);

int Verif_Cel_Hor(int **vert, int beginF, int endF, int beginC, int endC, int extre_c, int x, int y);

void Generacion_Plana(int **plana, int n, int m);

void Generacion_Vertical(int **vertical, int n, int m);

void Generacion_Horizontal(int **horizontal, int n, int m);

