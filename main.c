#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tarefa {
    char assunto [50];
    int horaInicio;
    int horaTermino;
    int grauEsforco;
    int prioridade;
}Tarefa;

typedef struct Reuniao {
    char assunto[50];
    int horaInicio;
    int horaTermino;
    char local[50];
    char presenca[15];
}Reuniao;

typedef struct Aniversario {
    char assunto[50];
    int horaInicio;
    int horaTermino;
    char local[50];
    char aniversariante[50];
}Aniversario;

typedef struct Usuario{
    char nome[50]; 
    char email[50];
    Tarefa t[50];
    Reuniao r[50];
    Aniversario a[50];
}Usuario;

Usuario CriaUsuario (char u [50], char e [50] ){  // Função que cria usuario com nome e e-mail
    Usuario novoUsuario;
    strcpy(novoUsuario.nome, u);
    strcpy(novoUsuario.email, e);
    return novoUsuario;
}

void VisualizaUsuario (Usuario c[], int tam){  //Função que imprime os usuarios criados na agenda
    printf("| nome                    | E-mail             |\n");
    for(int i = 0; i < tam; i++){
        printf("|%-35s", c[i].nome);
        printf("|%-20s", c[i].email);
    }
}
Tarefa CadastraTarefa (char a[50], int hI, int hT, int g, int p){  //Função que cadastra cada item do evento Tarefa
    Tarefa novaTarefa;
    strcpy(novaTarefa.assunto, a);
    novaTarefa.horaInicio = hI;
    novaTarefa.horaTermino = hT;
    novaTarefa.grauEsforco = g;
    novaTarefa.prioridade = p;
    return novaTarefa;
}
Reuniao CadastraReuniao (char a[50], int hI, int hT, char l[50], char p[15]){  //Função que cadastra cada item do evento Reunião
    Reuniao novaReuniao;
    strcpy(novaReuniao.assunto, a);
    novaReuniao.horaInicio = hI;
    novaReuniao.horaTermino = hT;
    strcpy(novaReuniao.local, l);
    strcpy(novaReuniao.presenca, p);
    return novaReuniao;
}

Aniversario CadastraAniversario (char a[50], int hI, int hT, char l[50], char an[50]){  //Função que cadastra cada item do evento Aniversario
    Aniversario novoAniversario;
    strcpy(novoAniversario.assunto, a);
    novoAniversario.horaInicio = hI;
    novoAniversario.horaTermino = hT;
    strcpy(novoAniversario.local, l);
    strcpy(novoAniversario.aniversariante, an);
    return novoAniversario;
}
void imprimaAgenda(Usuario ag[], int nA){  //Função que imprime os eventos da agenda de um usuário
    printf("| Tarefa: Assunto    | Inicio | Termino | Grau de Esforco | Prioridade |\n");
    for(int i = 0; i < 50; i++){
        if (ag[nA].t[i].horaInicio != 0){
            printf("|%-31s", ag[nA].t[i].assunto);
            printf("|%6d h", ag[nA].t[i].horaInicio);
            printf("|%7d h", ag[nA].t[i].horaTermino);
            printf("|%17d", ag[nA].t[i].grauEsforco);
            printf("|%12d|\n", ag[nA].t[i].prioridade);
        }
    }
    printf("| Reuniao: Assunto   | Inicio | Termino | Local           | presenca |\n");
    for(int i = 0; i < 50; i++){
        if (ag[nA].r[i].horaInicio){
            printf("|%-31s", ag[nA].r[i].assunto);
            printf("|%6d h", ag[nA].r[i].horaInicio);
            printf("|%7d h", ag[nA].r[i].horaTermino);
            printf("|%17s", ag[nA].r[i].local);
            printf("|%10s|\n", ag[nA].r[i].presenca);
        }
    }
    printf("| Niver: Assunto     | Inicio | Termino | Local           | Aniversariante |\n");
    for(int i = 0; i < 50; i++){
        if (ag[nA].a[i].horaInicio){
            printf("|%-31s", ag[nA].a[i].assunto);
            printf("|%6d h", ag[nA].a[i].horaInicio);
            printf("|%7d h", ag[nA].a[i].horaTermino);
            printf("|%17s", ag[nA].a[i].local);
            printf("|%16s|\n", ag[nA].a[i].aniversariante);
        }
    }
}


int main(){
    Usuario agenda[50]; //Agenda com 50 posições do tipo Usuario

    int opcao_usuario, opcao_agenda, hora_i, hora_t, grau, priorid;
    int numeroUsuario = 0, numeroAgenda, numeroTarefa = 0, numeroReuniao = 0, numeroAniversario = 0;
    char nome_u[50], nome_e[50], nome_a[50], espaco[50], x[15], nome_an[50];

        do{
        printf("\nMENU DO USUARIO\n");
        printf("1 - CRIAR USUARIO\n");
        printf("2 - LISTAR USUARIOAS\n");
        printf("3 - ENTRAR NA AGENDA\n");
        printf("0 - SAIR\n");
        printf("INFORME SUA OPCAO:\n");
        scanf ("%d", &opcao_usuario);
        switch (opcao_usuario){
            case 1:
                if(numeroUsuario >= 50){
                    printf("Limite de usuarios alcancado!\n");
                    break;
                }
                printf("\nMENU DE CRIACAO\n");
                setbuf(stdin, 0);
                printf("INFORME O NOME DO USUARIO:\n");
                fgets(nome_u,50,stdin);
                printf("INFORME O EMAIL:\n");
                fgets(nome_e,50,stdin);
                agenda[numeroUsuario] = CriaUsuario(nome_u, nome_e); //armazena as informações do usuario criado na posição vazia do vetor agenda
                numeroUsuario++;                
            break;
            case 2:
                printf("\nUSUARIOS CRIADOS\n");
                VisualizaUsuario(agenda, numeroUsuario);              
            break;
            case 3:
                setbuf(stdin, 0);
                printf("INFORME O NOME DO USUARIO:\n");
                fgets(nome_u,50,stdin);
                for (int i = 0; i < 50; i++){  //verifica em qual posição do vetor agenda o usuario vigente está alocado, para assim usar essa posição para as próximas ações
                    if(strcmp(agenda[i].nome, nome_u) == 0){
                        printf("Numero do usuario na agenda: %d\n", i);
                        numeroAgenda = i;
                        }
                }
                do{
                    printf("\nMENU DA AGENDA\n");
                    printf("1 - CADASTRAR TAREFA\n");
                    printf("2 - CADASTRAR REUNIAO\n");
                    printf("3 - CADASTRAR ANIVERSARIO\n");
                    printf("4 - IMPRIMIR AGENDA\n");
                    printf("0 - VOLTAR\n");
                    printf("INFORME SUA OPCAO:\n");
                    scanf ("%d", &opcao_agenda);
                    switch(opcao_agenda){
                    case 1:
                        if(numeroTarefa >= 50){
                            printf("Limite de Tarefas alcancado!\n");
                            break;
                        }
                        printf("\nMENU DA TAREFA\n");
                        setbuf(stdin, 0);
                        printf("INFORME O ASSUNTO:\n");
                        fgets(nome_a,50,stdin);
                        printf("INFORME O HORARIO DE INICIO:\n");
                        scanf("%d",&hora_i);
                            while (hora_i < 0 || hora_i > 23){  //impede o cadastro do horário fora do intervalo 
                                printf("Fora do intervalo!\n");
                                printf("INFORME O HORARIO DE INICIO:\n");
                                scanf("%d",&hora_i);
                            }
                        bool existe1 = 0;
                        for(int i = 0; i < 50; i++){  //impede o cadastro do evento com horario de inicio existente
                            if(hora_i == agenda[numeroAgenda].t[i].horaInicio || hora_i == agenda[numeroAgenda].r[i].horaInicio || hora_i == agenda[numeroAgenda].a[i].horaInicio){
                                printf("Ja existe evento com esse horario de inicio!\n");
                                existe1 = 1;
                            }
                        }
                        if(existe1)
                            break;
                        printf("INFORME O HORARIO DE TERMINO:\n");
                        scanf("%d",&hora_t);
                            while (hora_i < 0 || hora_t > 23){  //impede o cadastro do horário fora do intervalo 
                                    printf("Fora do intervalo!\n");
                                    printf("INFORME O HORARIO DE TERMINO:\n");
                                scanf("%d",&hora_t);
                            }
                        printf("INFORME O GRAU DE ESFORCO DE 1 A 5:\n");
                        scanf("%d",&grau);
                            while (grau < 0 || grau > 5){  //impede o cadastro do grau de esforço fora do intervalo 
                                    printf("Fora do intervalo!\n");
                                    printf("INFORME O GRAU DE ESFORCO DE 1 A 5:\n");
                                scanf("%d",&grau);
                            }
                        printf("INFORME A PRIORIDADE DE 1 A 10:\n");
                        scanf("%d",&priorid);
                            while (priorid < 0 || priorid > 10){  //impede o cadastro da prioridade fora do intervalo 
                                printf("Fora do intervalo!\n");
                                printf("INFORME A PRIORIDADE DE 1 A 10:\n");
                                scanf("%d",&priorid);
                            }
                        agenda[numeroAgenda].t[numeroTarefa] = CadastraTarefa(nome_a, hora_i, hora_t, grau, priorid);  //armazena as informações do evento na agenda do usuario vigente na posição vazia do vetor do evento
                        numeroTarefa++;
                    break;
                    case 2:
                        if(numeroReuniao >= 50){
                            printf("Limite de Reuniao alcancado!\n");
                            break;
                        }
                        printf("\nMENU DA REUNIAO\n");
                        setbuf(stdin, 0);
                        printf("INFORME O ASSUNTO:\n");
                        fgets(nome_a,50,stdin);
                        printf("INFORME O HORARIO DE INICIO:\n");
                        scanf("%d",&hora_i);
                        while(hora_i < 0 || hora_i > 23){  //impede o cadastro do horário fora do intervalo 
                            printf("Fora do intervalo!\n");
                            printf("INFORME O HORARIO DE INICIO:\n");
                            scanf("%d",&hora_i);
                        }
                        bool existe2 = 0;
                        for(int i = 0; i < 50; i++){  //impede o cadastro do evento com horario de inicio existente
                            if(hora_i == agenda[numeroAgenda].t[i].horaInicio || hora_i == agenda[numeroAgenda].r[i].horaInicio || hora_i == agenda[numeroAgenda].a[i].horaInicio){
                                printf("Ja existe evento com esse horario de inicio!\n");
                                existe2 = 1;
                            }
                        }
                        if(existe2)
                            break;
                        printf("INFORME O HORARIO DE TERMINO:\n");
                        scanf("%d",&hora_t);
                            while(hora_i < 0 || hora_t > 23){  //impede o cadastro do horário fora do intervalo 
                                printf("Fora do intervalo!\n");
                                printf("INFORME O HORARIO DE TERMINO:\n");
                                scanf("%d",&hora_t);
                            }
                        setbuf(stdin, 0);
                        printf("INFORME O LOCAL:\n");
                        fgets(espaco,50,stdin);
                        printf("local eh: %s\n", espaco);
                        printf("PRESENCA OBRIGATORIA?:\n");
                        scanf("%s", x);                        
                        agenda[numeroAgenda].r[numeroReuniao] = CadastraReuniao(nome_a, hora_i, hora_t, espaco, x);  //armazena as informações do evento na agenda do usuario vigente na posição vazia do vetor do evento
                        numeroReuniao++;
                    break;
                    case 3:
                        if(numeroAniversario >= 50){
                            printf("Limite de Aniversario alcancado!\n");
                            break;
                        }
                        printf("\nMENU D ANIVERSARIO\n");
                        setbuf(stdin, 0);
                        printf("INFORME O ASSUNTO:\n");
                        fgets(nome_a,50,stdin);
                        printf("INFORME O HORARIO DE INICIO:\n");
                        scanf("%d",&hora_i);
                        bool existe3 = 0;
                        for(int i = 0; i < 50; i++){  //impede o cadastro do evento com horario de inicio existente
                            if(hora_i == agenda[numeroAgenda].t[i].horaInicio || hora_i == agenda[numeroAgenda].r[i].horaInicio || hora_i == agenda[numeroAgenda].a[i].horaInicio){
                                printf("Ja existe evento com esse horario de inicio!\n");
                                existe3 = 1;
                            }
                        }
                        if(existe3)
                            break;
                        printf("INFORME O HORARIO DE TERMINO:\n");
                        scanf("%d",&hora_t);
                        setbuf(stdin, 0);
                        printf("INFORME O LOCAL:\n");
                        fgets(espaco,50,stdin);
                        setbuf(stdin, 0);
                        printf("INFORME O NOME DO ANIVERSARIANTE:\n");
                        fgets(nome_an, 50, stdin);
                        agenda[numeroAgenda].a[numeroAniversario] = CadastraAniversario(nome_a, hora_i, hora_t, espaco, nome_an);  //armazena as informações do evento na agenda do usuario vigente na posição vazia do vetor do evento
                        numeroAniversario++;
                    break;
                    case 4:
                        printf("\nEVENTOS CADASTRADOS NA AGENDA\n");
                        imprimaAgenda(agenda, numeroAgenda);
                    break;
                    }
                }while (opcao_agenda != 0);
            break;
            case 0:
            break;
        }
        }while(opcao_usuario != 0);
return 0;
}
