#ifndef ADVOGADO_H
#define ADVOGADO_H

typedef struct advogado{
    char cpf[15];
    char nome[50];
    char carteiraOAB[12];       // Ex: 123456/SP , 78910-RJ , 98765 RN     
    char especialidade[50];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
} Advogado;

void moduloAdvogado(void);
int menuAdvogado(void);
void cadastraAdvogado(void);
void mostraAdvogado(void);
void editaAdvogado(void);
void excluiAdvogado(void);

#endif