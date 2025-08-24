#ifndef AFD_H
#define AFD_H
#define NUM_ESTADOS 7
#define NUM_CLASES 6
#define MAX_PALABRA 256

enum { Q0, Q1, Q2, Q3, Q4, Q5, ERROR };

int es_final(int estado);
int clasificar(char c);
int mover(int estado, char c);

#endif
