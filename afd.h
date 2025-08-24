#ifndef AFD_H
#define AFD_H
#define NUM_ESTADOS 7
#define NUM_ CLASES 6

enum{Q1,Q2,Q3,Q4,Q5,Q6,ERROR};

int es_final(int estado);
int clasificar(char c);
int mover(int estado,char c);


#endif