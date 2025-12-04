#ifndef CLIENTEPF_H
#define CLIENTEPF_H

typedef struct clientePF{
    int atividade;
    char cpf[16];
    char nome[50];
    char sexo[15];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
    char idProcesso[20];
    struct clientePF *prox;
} ClientePF;

void moduloClientePF(void);
int menuClientePF(void);
void cadastraClientePF(void);
void mostraClientePF(void);
void editaClientePF(void);
void excluiClientePF(void);
void lixeiraClientePF(void);
void relatorioClientePF(void);
void listaClientePF(void);

#endif