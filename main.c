#include "afd.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Uso: %s archivo.txt\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    perror("Error al abrir archivo");
    return 1;
  }

  char palabra[MAX_PALABRA];
  int indice = 0;
  int estado = Q0;
  int c;

  while ((c = getc(fp)) != EOF) {
    if (c == ',' || c == '\n') {
      palabra[indice] = '\0'; // cerrar string
      if (indice > 0) {
        if (es_final(estado))
          printf("%s -> VALIDA\n", palabra);
        else
          printf("%s -> INVALIDA\n", palabra);
      }
      // reiniciar
      indice = 0;
      estado = Q0;
    } else if (c != ' ' && c != '\t') { // ignorar espacios
      palabra[indice++] = (char)c;
      estado = mover(estado, c);
    }
  }

  // Última palabra si no termina con coma
  if (indice > 0) {
    palabra[indice] = '\0';
    if (es_final(estado))
      printf("%s -> VALIDA\n", palabra);
    else
      printf("%s -> INVALIDA\n", palabra);
  }

  fclose(fp);
  return 0;
}
