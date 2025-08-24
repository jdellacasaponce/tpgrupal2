#include "afd.h"

// Tabla de transiciones
int transiciones[NUM_ESTADOS][NUM_CLASES] = {
    /* Q0 */ {Q1, Q2, Q2, ERROR, ERROR, ERROR},
    /* Q1 */ {Q5, Q5, ERROR, Q3, ERROR, ERROR},
    /* Q2 */ {Q2, Q2, Q2, ERROR, ERROR, ERROR},
    /* Q3 */ {Q4, Q4, Q4, ERROR, Q4, ERROR},
    /* Q4 */ {Q4, Q4, Q4, ERROR, Q4, ERROR},
    /* Q5 */ {Q5, Q5, ERROR, ERROR, ERROR, ERROR},
    /* ERROR */ {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}};

int es_final(int estado) {
  return (estado == Q1 || estado == Q2 || estado == Q4 || estado == Q5);
}

int clasificar(char c) {
  if (c == '0')
    return 0;
  if (c > '0' && c <= '7')
    return 1;
  if (c >= '8' && c <= '9')
    return 2; // incluye 0-7
  if (c == 'x' || c == 'X')
    return 3;
  if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    return 4;
  return 5;
}

int mover(int estado, char c) {
  int clase = clasificar(c);
  return transiciones[estado][clase];
}
