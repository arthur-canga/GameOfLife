//
// Biblioteca de validación
// Arturo Canga. V-25.696.222
// Luis Fernandez. V-
// Para AyPII. Primer Proyecto. Creado el 7/6/20
//

char *lectura(char *name, int namesize);

void eliminarespacios(char *s);

int balanceyvalores(const char *s);

int limiter(const char array[]);

int check(const char array[], int limit);

int esfila(const char s[],int size);

int loner(const char *s, int size);

int getdimY(const char *s);

int getdimX(const char *s);

int **generatematrix(char *string, int *X, int *Y);

char *obtainer(char *s, int namesize);