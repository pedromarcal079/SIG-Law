#ifndef AGENDAPROC_H
#define AGENDAPROC_H

typedef struct agendamento {
    int idAgend;
    char idProc[5];
    char hora[7];
    char data[13];
    char tipo[30];
    char local[50];         
    char observacao[150];
    char status[20];
    char tipoCliente[5];
} Agendamento;

void moduloAgendaProc(void);
int menuAgendaProc(void);
void agendaProces(void);
void mostraAgendaProces(void);

int gerarID_Agenda(void);

#endif

//Agendar Processo:
//ID do agendamento (automático)
//ID do processo
//Horário
//Data
//Tipo (audiência, reunião, consulta, prazo, etc.)
//Local (Online, tribunal, etc.)(??)
//Descrição
//Status (pendente, realizado, cancelado)
