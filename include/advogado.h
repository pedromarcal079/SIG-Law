#ifndef ADVOGADO_H
#define ADVOGADO_H

typedef struct advogado{
    int atividade;
    char cpf[15];
    char nome[50];
    char carteiraOAB[20];       // Ex: 123456/SP , 78910-RJ , 98765 RN     
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
void lixeiraAdvogado(void);
void relatorioAdvogado(void);

#endif