#ifndef PROCESSOSPJ_H
#define PROCESSOSPJ_H

typedef struct processoPJ{
    int id;
    int atividade;
    char tipo[30];              // cível, trabalhista, penal, tributário, família, etc.
    char autor[21];             // CNPJ
    char reu[21];               // CPF ou CNPJ
    char advOAB[20];          // carteira oab do advogado
    char descricao[200];
    char status[20];
    char data[13];
} ProcessoPJ;

void moduloProcPJ(void);
int menuProcessoPJ(void);
void cadastraProcessoPJ(void);
void mostraProcessoPJ(void);
void editaProcessoPJ(void);
void excluiProcessoPJ(void);

int gerarID_PJ();

#endif