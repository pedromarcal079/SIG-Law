#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

typedef struct clientePJ{
    int atividade;
    char cnpj[21];      
    char razaoSocial[100];      // Nome legal da empresa (Ex.: The Coca-Cola Company)
    char nomeFantasia[100];     // Nome comercial da empresa (Ex.: Coca-Cola)
    char repres[50];     // Nome do representante da empresa
    char cpfRepres[16];  // CPF do Representante
    char areaAtuacao[50];     // Área de atuação da empresa
    char endereco[100];         
    char email[100];         
    char telefone[20];   
    char idProcesso[20];
    struct clientePJ *prox;
} ClientePJ;

void moduloClientePJ(void);
int menuClientePJ(void);
void cadastraClientePJ(void);
void mostraClientePJ(void);
void editaClientePJ(void);
void excluiClientePJ(void);
void lixeiraClientePJ(void);
void relatorioClientePJ(void);
void listaClientePJ(void);

#endif