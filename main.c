#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    FILE *archivo;
    char buffer[100];
    
    if (argc!=2) {
        printf("Cantidad de argumentos inválida");
        return 0;
    }

    archivo = fopen(argv[1], "r");

    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("%s", buffer);
    }

    fclose(archivo);

    return 0;
}