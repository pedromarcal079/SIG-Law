#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>
#include "validacao.h"
#include <stdbool.h>


int vali_cpf(const char* cpf){
    if (strlen(cpf) == 0){
        printf("Coloque um cpf que não esteja vazio!\n");
        return false;
    }
    if (strlen(cpf) != 11){
        printf("CPF INVALIDO!\n");
        return false;
    }
    for (int i = 0; cpf[i] != '\0'; i++){
        if(!iswdigit(cpf[i]) || cpf[i] == ' '){
            printf("Coloque apenas números!\n");
            return false;
        }
    }
    return true;
}

int vali_nome(const char* nome){
    if (strlen(nome) == 0){
        printf("Coloque um nome que não esteja vazio!\n");
        return false;
    }

    for (int i = 0; nome[i] != '\0'; i++){
        if(!iswalpha(nome[i]) && nome[i] != ' '){
            printf("Coloque apenas letras e espaços!\n");
            return false;
        }
    }
    return true;
}

int vali_carteiraOAB(const char* carteiraOAB){
    if (strlen(carteiraOAB) == 0){
        printf("Coloque uma carteira que não esteja vazia!\n");
        return false;
    }
    
    if (strlen(carteiraOAB) < 13) {
        printf("A carteira esta incompleta!\n");
        printf("Ex: OAB/RN 123456\n");
        return false;
    }
    
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
    
    return true;
}

int vali_dataNasc(const char* dataNasc){
    int i = 0;

    if (strlen(dataNasc) == 0){
        printf("|  Coloque um nome que não esteja vazio!\n");
        return false;
    }

    if(strlen(dataNasc) != 8){
        printf("|  Data Invalida!\n");
        return false;
    }

    while (dataNasc[i] != '\0'){
        if(!iswdigit(dataNasc[i])){
            printf("|  Coloque apenas os números!\n");
            printf("|  Ex: 01012025\n");
            return false;
        }
        i++;
    }
    return true;
}

int vali_telefone(const char* telefone){
    if (strlen(telefone) == 0){
        printf("Coloque um telefone que não esteja vazio!\n");
        return false;
    }
    for (int i = 0; telefone[i] != '\0'; i++){
        if(!iswdigit(telefone[i]) || telefone[i] == ' '){
            printf("Coloque apenas números!\n");
            return false;
        }
    }
    return true;
}

int vali_sexo(char* sexo){
    if(strlen(sexo) == 0){
        printf("\tDigite 'm' ou 'f'\n");
        return false;
    }
    if(sexo[0] == 'm' || sexo[0] == 'M'){
        return true;
    }
    else if(sexo[0] == 'f' || sexo[0] == 'F'){
        return true;
    }
    else{
        printf("\tGenero incorreto!\n");
        return false;
    }
}

int vali_data(char* data) {
    int dia, mes, ano;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("\n\t[!] Formato invalido! Use DD/MM/AAAA (Ex: 15/05/2024)\n");
        return false;
    }

    if (ano < 1900 || ano > 2100) {
        printf("\n\t[!] Ano invalido! Digite entre 1900 e 2100.\n");
        return false;
    }
    if (mes < 1 || mes > 12) {
        printf("\n\t[!] Mes invalido! Digite entre 01 e 12.\n");
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes]) {
        printf("\n\t[!] Dia invalido! O mes %d vai ate o dia %d.\n", mes, diasNoMes[mes]);
        return false;
    }

    return true; 
}