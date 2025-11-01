#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>
#include "validacao.h"
#include <stdbool.h>


int vali_cpf(const char* cpf){
    int i = 0;
    if (strlen(cpf) == 0){
        printf("Coloque um cpf que não esteja vazio!\n");
        return false;
    }
    while (cpf[i] != '\0'){
        if(!iswdigit(cpf[i]) || cpf[i] == ' '){
            printf("Coloque apenas números!\n");
            return false;
        }
        i++;
    }
    return true;
}

int vali_nome(const char* nome){
    int i = 0;
    if (strlen(nome) == 0){
        printf("Coloque um nome que não esteja vazio!\n");
        return false;
    }

    while (nome[i] != '\0'){
        if(!iswalpha(nome[i]) && nome[i] != ' '){
            printf("Coloque apenas letras e espaços!\n");
            return false;
        }
        i++;
    }
    return true;
}