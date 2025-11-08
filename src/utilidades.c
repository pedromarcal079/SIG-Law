#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

void input(char *variavel, int tam, char *mensagem){

    int len;
    printf("%s", mensagem);
    fgets(variavel, tam, stdin);
    len = strlen(variavel);
    if(len > 0 && variavel[len-1] == '\n'){
        variavel[len-1] = '\0';
    }
}