#ifndef PROCESSOSPF_H
#define PROCESSOSPF_H

typedef struct processoPF{
        int id;
        int atividade;
        char tipo[30];              // cível, trabalhista, penal, tributário, família, etc.
        char autor[16];             // CPF
        char reu[21];               // CPF ou CNPJ
        char advOAB[20];          // carteira oab do advogado
        char descricao[200];
        char status[20];
        char data[13];
    } ProcessoPF;

void moduloProcPF(void);
int menuProcessoPF(void);
void cadastraProcessoPF(void);
void mostraProcessoPF(void);
void editaProcessoPF(void);
void excluiProcessoPF(void);
void lixeiraProcessoPF(void);
void relatorioProcessosPF(void);

char* gerarID_PJ();

#endif