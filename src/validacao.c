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

int vali_carteiraOAB(const char* carteiraOAB){
    int i = 0;
    if (strlen(carteiraOAB) == 0){
        printf("Coloque um nome que não esteja vazio!\n");
        return false;
    }

    while (carteiraOAB[i] != '\0'){
        if (carteiraOAB[0] != 'O') {
        printf("A carteira deve conter 'OAB' como o início da carteira (posição 0)!\n");
        printf("Ex: OAB/RN 123456\n");
        return false;
        }
        else if (carteiraOAB[1] != 'A') {
            printf("A carteira deve conter 'OAB' como o início da carteira (posição 1)!\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        else if (carteiraOAB[2] != 'B') {
            printf("A carteira deve conter 'OAB' como o início da carteira (posição 2)!\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        else if (carteiraOAB[3] != '/') {
            printf("Deve haver uma barra logo após de 'OAB'!\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        else if (!iswupper(carteiraOAB[4])) {
            printf("Após a barra você deve colocar a sigla do estado em que o advogado exerce sua função.\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        else if (!iswupper(carteiraOAB[5])) {
            printf("Após a barra você deve colocar a sigla do estado em que o advogado exerce sua função.\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        else if (carteiraOAB[6] != ' ') {
            printf("Deve conter um espaço entre o estado e a numeração da carteira!\n");
            printf("Ex: OAB/RN 123456\n");
            return false;
        }
        for (int i = 7; i <= 12; i++) {
            if (carteiraOAB[i] == '\0') {
                printf("A numeração da carteira está incompleta (precisa de 6 dígitos)!\n");
                printf("Ex: OAB/RN 123456\n");
                return false;
            }
            if (!iswdigit(carteiraOAB[i])) {
                printf("A numeração deve conter apenas números (dígitos)!\n");
                printf("Ex: OAB/RN 123456\n");
                return false;
            }
        }
        i++;
    }
    return true;
}

int vali_dataNasc(const char* dataNasc){
    int i = 0;
    if (strlen(dataNasc) == 0){
        printf("Coloque um nome que não esteja vazio!\n");
        return false;
    }

    while (dataNasc[i] != '\0'){
        if(!iswdigit(dataNasc[i])){
            printf("Coloque apenas os números!\n");
            printf("Ex: 01012025");
            return false;
        }
        i++;
    }
    return true;
}

int vali_telefone(const char* telefone){
    int i = 0;
    if (strlen(telefone) == 0){
        printf("Coloque um telefone que não esteja vazio!\n");
        return false;
    }
    while (telefone[i] != '\0'){
        if(!iswdigit(telefone[i]) || telefone[i] == ' '){
            printf("Coloque apenas números!\n");
            return false;
        }
        i++;
    }
    return true;
}