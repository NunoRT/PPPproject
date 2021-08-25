//
//  compiling_error.h
//  FICHEIROS
//
//  Created by Rafael Baptista on 01/05/2019.
//  Copyright © 2019 Rafael Baptista. All rights reserved.
//

#ifndef compiling_error_h
#define compiling_error_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 200

typedef struct user *Luser;
typedef struct cid *Lcid;
typedef struct pdi *Lpdi;
typedef struct todos_pdi *Ltodos;

typedef struct todos_pdi{
  Lpdi pdi_aux;
  Ltodos prox;
}Todos_pdi;

typedef struct{
  int dia,mes,ano;
}Data;

typedef struct user{
  char nome[SIZE];
  char morada[SIZE];
  Data nasc;
  char tel[SIZE];
  Ltodos pdis_u;
  Lcid cids_u;
  Ltodos hot;
  Luser prox;
}User;

typedef struct cid{
  int ncid, npdi, num;
  char nome[SIZE];
  int popular_cid;
  Lpdi lista_pdi;
  Lcid prox;
}Cid;

typedef struct pdi{
  char nome[SIZE];
  char desc[SIZE];
  int hori,mini,horf,minf,popular_pdi, num;
  Lpdi prox;
}Pdi;

/*DECLARAÇÃO DE FUNÇÕES*/

void fazregisto(Luser lista_users);
void fazlogin(Luser lista_users, Lcid lista_cids, Ltodos Pdis_pref);
void menu(Luser lista_users, Luser headuser, Lcid lista_cids, Ltodos Pdis_pref);
void limpa();
Luser insere_Luser(Luser l, Luser novo);
Luser faz_lista_users(Luser l,char nom[SIZE],char morad[SIZE],Data nas,char te[SIZE]);
Luser le_user(Luser l);
int verifica_ficheiro();
void le_data(FILE * f,Data * nasc);
void le_morada(FILE *f, char morada[]);
void imprime_lista_pdis_pref(Ltodos Pdis_pref);
void imprime_lista_users(Luser lista_users);
Lcid imprime_lista_cids(Lcid cids_u);
Luser estrutura_user(Luser l);
void atualiza_fich_user(Luser lista_users);
Luser insere_sort(Luser l, Luser novo);
Lcid * insere_Lcid(Lcid * l, Lcid nova);
Lpdi * insere_Lpdi(Lpdi * li, Lpdi novo);
Lcid faz_lista_cids(Lcid * l,int ncids,int npdis,char nom[SIZE],int popular_cd);
Lpdi faz_lista_pdis(Lpdi * li,char nom[],char des[],int hoi,int mii,int hof,int mif,int popular_pd,int j);
Lcid le_fich_cidpd(Lcid l,Lpdi li);
void imprime_bem(Lcid cidades);
Lcid procura_cid(Lcid lista_cid, char nome[]);
Ltodos procura_pdi(Ltodos lista_pdi, char nome[]);
Luser procura_nome_user(Luser lista_user, char nome[]);
Ltodos faz_lista_todos(Lcid lista_cids, Ltodos lis);
Ltodos inserir_Ltodos(Ltodos lis, Ltodos novo);
Ltodos insere_pdiu(Ltodos lpdiu, Ltodos novo);
Ltodos faz_lista_lpdiu(Ltodos pdis_u, Ltodos increm_pd);
Lcid encontra_no(Lcid lista_cid, int num);
Lcid insere_cidu(Lcid lcidu, Lcid novo);
Lcid faz_lista_lcidu(Lcid cids_u, Lcid increm_pd);
int procura_cid_fav(Lcid lista_cid, char nome[]);
int procura_pdi_fav(Ltodos lista_pdi, char nome[]);
void remove_cids(Lcid cids_u, char nome[]);
Ltodos remove_hot(Ltodos hot);
void remove_pdis(Ltodos pdis_u, char nome[]);
Lpdi procura_se_esta_na_cid(Lcid lista_cids, Lcid cids_u);
Lpdi copia_mem(Lpdi retorna, Lcid aux);
Lcid limpar(Lcid lpdiu);


/*CÓDIGO DAS FUNÇÕES*/

void fazregisto(Luser lista_users){

  FILE *f;
  char n[SIZE];
  char morada[SIZE];
  char data[SIZE];
  int dia;
  int mes;
  int ano;
  Luser utilizador = (Luser)malloc(sizeof(User));
  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Registos.txt", "a");

  if(f == 0){
        printf("\t\t\t\tImpossivel abrir arquivo...\n");
        exit(1); }
  else{
    fgets(utilizador->nome, SIZE, stdin);
    system("clear");
    printf("\n\n\n\t\t\t\t---------------------- (DEI)XA PLANEAR A TUA VIAGEM ------------------------\t\t\t\t\n\n\n");
    printf("\n\n\t\t\t\tREGISTO\n\t\t\t\t-----------\n\n");
    do{
      printf("\t\t\t\tInsira o nome:  ");
      fflush(stdin);
      fgets(n, SIZE, stdin);
      n[strcspn(n, "\n")] = 0;
      if (procura_nome_user(lista_users, n) != NULL){
        printf("\n\t\t\t\tNome de utilizador já utilizado!\n");
      }
    }while(procura_nome_user(lista_users, n) != NULL);
    strcpy(utilizador->nome,n);
    fprintf(f,"%s\n", utilizador->nome);
    printf("\n\t\t\t\tInsira a morada:  ");
    fgets(utilizador->morada, SIZE, stdin);
    utilizador->morada[strcspn(utilizador->morada, "\n")] = 0;
    fprintf(f,"%s\n", utilizador->morada);


    do {
      printf("\n\t\t\t\tInsira o dia:  ");
      scanf(" %d", &dia);
      if (dia > 31 || dia < 1) {
        printf("\t\t\t\tDia inválido!\n");
      }
    } while (dia > 31 || dia < 1);
    utilizador->nasc.dia = dia;


    do {
      printf("\n\t\t\t\tInsira o mês:\t");
      scanf(" %d", &mes);
      if (mes > 12 || mes < 1 || (dia > 29 && mes == 2)) {
        printf("\t\t\t\tMês inválido!\n");
      }
    } while (mes > 12 || mes < 1 || (dia > 29 && mes == 2));
    utilizador->nasc.mes = mes;


    do {
      printf("\n\t\t\t\tInsira o ano:\t");
      scanf(" %d", &ano);
      if (ano > 2019 || ano < 1903) {
        printf("\t\t\t\tAno inválido!\n");
      }
    } while (ano > 2019 || ano < 1903);
    utilizador->nasc.ano = ano;
    fprintf(f,"%d/%d/%d\n", utilizador->nasc.dia,utilizador->nasc.mes,utilizador->nasc.ano);


    fgets(utilizador->tel, SIZE, stdin);
    do {
      printf("\n\t\t\t\tInsira o telefone:  ");
      fgets(utilizador->tel, SIZE, stdin);
      utilizador->tel[strcspn(utilizador->tel, "\n")] = 0;
      if (strlen(utilizador->tel) != 9) {
        printf("\t\t\t\tTelefone inválido! Reveja o número de dígitos inseridos!\n");
      }
    } while (strlen(utilizador->tel) != 9);
    utilizador->tel[strcspn(utilizador->tel, "\n")] = 0;
    fprintf(f,"%s\n", utilizador->tel);

    fseek(f, 0, SEEK_SET);
    fclose(f);
    fflush(stdin);
    insere_Luser(lista_users,utilizador);
    system("sleep 02");
  }
}

void fazlogin(Luser lista_users, Lcid lista_cids, Ltodos Pdis_pref){
  int TamStr, i;
  char nome_copy[SIZE];
  char nome_guarda[SIZE];
  FILE *f;
  char n[SIZE];
  char num[SIZE];
  Luser headuser = NULL;
  headuser = (Luser)malloc(sizeof(User));
  if (lista_users->prox == NULL){
    printf("Lista Vazia\n\n");
    exit(1);
  }
    printf("\n\n\t\t\t\tLOGIN\n\t\t\t\t_______\n\n");
    do{
      printf("\t\t\t\tInsira o nome:  ");
      fflush(stdin);
      scanf("%s", n);
      n[strcspn(n, "\n")] = 0;
      if (procura_nome_user(lista_users, n) == NULL){
        printf("\n\t\t\t\tNenhum utilizador com esse nome!\n");
      }
    }while(procura_nome_user(lista_users, n) == NULL);

    headuser = procura_nome_user(lista_users, n);

    strcpy(nome_copy, n);
    TamStr = strlen(nome_copy);
    for(i=0; i<TamStr; i++)
    {
      nome_copy[i] = toupper (nome_copy[i]);
    }
  printf("\n\n\t\t\t\tLOGIN EFETUADO! BEM_VINDO(A) %s\n\n\n", nome_copy);
  system("sleep 01");
  limpa();
  menu(lista_users, headuser, lista_cids, Pdis_pref);

}

void menu(Luser lista_users, Luser headuser, Lcid lista_cids, Ltodos Pdis_pref){

  FILE *f;
  int num, num2, r;
  char c;
  char n[SIZE];
  int dia;
  int mes;
  int ano;
  lista_users = headuser;
  Lcid aux2;
  Ltodos aux3;
  Lcid aux4;
  Lcid increm_cid = NULL;
  increm_cid = (Lcid)malloc(sizeof(Cid));
  Ltodos increm_pdi = NULL;
  increm_pdi = (Ltodos)malloc(sizeof(Todos_pdi));
  Lcid cids_u = NULL;
  Ltodos pdis_u = NULL;
  Ltodos hot = NULL;
  Lpdi lista_pdi = NULL;
  Lcid remove_cid = NULL;
  Ltodos remove_pdi = NULL;
  Lpdi pesquisa_cid;
  Lpdi walker;
  Lcid viagem = NULL;

  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Registos.txt", "r");
  do{
    printf("\n\n\t\t\t\t\t-------------------- MENU PRINCIPAL -------------------------\t\t");
    printf("\n\n\n\t\t\t\t\tEscolha uma opção:\t\t\t\t\t\n\n\n");
    printf("\t\t\t\tAlterar as definições de utilizador.....1\t\t\n\n");
    printf("\t\t\t\tListagem das cidades e pdis respetivos..2\t\t\n\n");
    printf("\t\t\t\tAdicionar/remover preferências..........3\t\t\n\n");
    printf("\t\t\t\tListagem de locais e pdis populares.....4\t\t\n\n");
    printf("\t\t\t\tConstruir a viagem......................5\t\t\n\n");
    printf("\t\t\t\tSair....................................6\t\t\n\n");
    printf("\t\t\t\tEscolha: ");
    scanf("%d", &num);

    switch(num){
      case 1:
      printf("\n\t\t\t\tA ACEDER AOS SEU DADOS...\n");
      system("sleep 01");

      printf("\n\n\t\t\t\tNOME:.....................%s", headuser->nome);
      printf("\n\t\t\t\tMORADA:...................%s", headuser->morada);
      printf("\n\t\t\t\tDATA DE NASCIMENTO:.......%02d/%02d/%d", headuser->nasc.dia,headuser->nasc.mes,headuser->nasc.ano);
      printf("\n\t\t\t\tTELEFONE:.................%s", headuser->tel);

      printf("\n\n\t\t\t\tQual a informação que deseja alterar?\n\n\t\t\t\tNome..................1\n\n\t\t\t\tMorada................2\n\n\t\t\t\tData de nascimento....3\n\n\t\t\t\tNº de telefone........4\n\n\t\t\t\tSair..................5\n\n\t\t\t\tEscolha:\t");
      scanf("%d", &num2);
      fflush(stdin);
      switch(num2){
        case 1:
        fgets(headuser->nome, SIZE, stdin);
        printf("\n\n\t\t\t\tDigite o novo nome:  ");
        fgets(headuser->nome, SIZE, stdin);
        headuser->nome[strcspn(headuser->nome, "\n")] = 0;
        printf("\n\n\t\t\t\tMudou o nome para: %s\n", headuser->nome);
        system("sleep 02");
        break;

        case 2:
        fgets(headuser->morada, SIZE, stdin);
        printf("\n\n\t\t\t\tDigite a nova morada:  ");
        fgets(headuser->morada, SIZE, stdin);
        headuser->morada[strcspn(headuser->morada, "\n")] = 0;
        printf("\n\n\t\t\t\tMudou a morada para: %s\n", headuser->morada);
        system("sleep 02");
        break;

        case 3:
        do { // -> dia
          printf("\n\t\t\t\tInsira o novo dia:\t");
          scanf("%d", &dia);
          if (dia > 31 || dia < 1) {
            printf("\n\t\t\t\tDia inválido!\n");
          }
        } while (dia > 31 || dia < 1);
        headuser->nasc.dia = dia;


        do { //-> mes
          printf("\n\t\t\t\tInsira o novo mês:\t");
          scanf("%d", &mes);
          if (mes > 12 || mes < 1 || (dia > 29 && mes == 2)) {
            printf("\n\t\t\t\tMês inválido!\n");
          }
        } while (mes > 12 || mes < 1 || (dia > 29 && mes == 2));
        headuser->nasc.mes = mes;


        do { //-> ano
          printf("\n\n\t\t\t\tInsira o novo ano:\t");
          scanf("%d", &ano);
          if (ano > 2019 || ano < 1903) {
            printf("\n\t\t\t\tAno inválido!\n");
          }
        } while (ano > 2019 || ano < 1903);
        headuser->nasc.ano = ano;

        printf("\n\n\t\t\t\tMudou para a data: %02d/%02d/%d\n",dia,mes,ano);
        fprintf(f,"%d/%d/%d\n", headuser->nasc.dia,headuser->nasc.mes,headuser->nasc.ano);
        system("sleep 02");
        break;

        case 4:
        fgets(headuser->tel, SIZE, stdin);
        do { // -> telefone
          printf("\n\n\t\t\t\tInsira o novo número de telefone:  ");
          fgets(headuser->tel, SIZE, stdin);
          headuser->tel[strcspn(headuser->tel, "\n")] = 0;
          if (strlen(headuser->tel) != 9) {
            printf("\n\t\t\t\tTelefone inválido! Reveja o número de dígitos inseridos!\n");
          }
        } while (strlen(headuser->tel) != 9);
        printf("\n\n\t\t\t\tMudou o número para: %s\n", headuser->tel);
        system("sleep 02");
        break;

        case 5:
        break;

        default:
        printf ("\n\t\t\t\tVALOR INVÁLIDO!\n");
        system("sleep 01");

      }break;

      case 2:
      printf("\n\t\t\t\tLISTANDO....\n");
      imprime_bem(lista_cids);
      printf("\n\n\t\t\t\tSair.................1\n\t\t\t\t");
      scanf("%d", &num);
      do {
        if (num == 1){
          break;
        }
        else{
          printf("\n\t\t\t\tCaracter inválido!\n");
        }
      }while (num == 1);
      break;

      case 3:
      printf("\n\t\t\t\tA ACEDER À LISTA...\n");
      system("sleep 0.5");
      do {
        printf("\n\t\t\t\tPRETENDE ADICIONAR OU REMOVER? (A/R)  ");
        scanf(" %c", &c);
        if (c == 'A'|| c =='a'){
          imprime_bem(lista_cids);
          printf("\n\n\t\t\t\t(Dê scroll para cima para visualizar toda a lista)\n\n\t\t\t\tCIDADE.....................1\n\t\t\t\tPONTO DE INTERESSE.........2\n");
          do {
            printf("\n\t\t\t\tESCOLHA:\t");
            scanf("%d", &num);
            fflush(stdin);
            if (num == 1){
              fgets(n, SIZE, stdin);

              do{
                printf("\t\t\t\tInsira o nome da cidade:  ");
                fflush(stdin);
                fgets(n, SIZE, stdin);
                n[strcspn(n, "\n")] = 0;

                if(cids_u==NULL){
                  lista_cids->num = 0;
                  if (procura_cid_fav(lista_cids, n) == 1){
                    printf("\n\t\t\t\tCidade encontrada!\n");
                    increm_cid = procura_cid(lista_cids, n);
                    cids_u = faz_lista_lcidu(cids_u,increm_cid);
                    (increm_cid->popular_cid)++;
                    (lista_cids->num)++;
                  }
                  else{
                    printf("\n\t\t\t\tCidade não encontrada!\n");
                  }
                  break;
                }
                r = procura_cid_fav(cids_u, n);
                if(r==0){
                  if (procura_cid_fav(lista_cids, n) == 1){
                    printf("\n\t\t\t\tCidade encontrada!\n");
                    increm_cid = procura_cid(lista_cids, n);
                    if (lista_cids->num >= 3){
                      printf("\n\t\t\t\tJá tem o máximo de locais permitidos!\n");
                      break;
                    }
                    else{
                      cids_u = faz_lista_lcidu(cids_u,increm_cid);
                      (increm_cid->popular_cid)++;
                      (lista_cids->num)++;
                    }
                  }
                  else{
                    printf("\n\t\t\t\tCidade não encontrada!\n");
                  }
                }
                else{
                  printf("Cidade já registada!");
                }
              }while(procura_cid_fav(cids_u, n) == 0);

            }
            else if (num == 2){
              do{
                printf("\n\t\t\t\tQUER INSERIR O PONTO HOT? (S/N)  ");
                scanf(" %c", &c);
                if (c == 'S' || c == 's'){
                  fgets(n, SIZE, stdin);
                  aux3 = Pdis_pref;
                  do{
                    printf("\t\t\t\tInsira o nome do ponto de interesse:  ");
                    fflush(stdin);
                    fgets(n, SIZE, stdin);
                    n[strcspn(n, "\n")] = 0;
                    if(hot == NULL){
                      if (procura_pdi_fav(Pdis_pref, n) == 1){
                        printf("\n\t\t\t\tPonto de interesse encontrado!\n");
                        increm_pdi = procura_pdi(aux3, n);
                        hot = faz_lista_lpdiu(hot,increm_pdi);
                        hot->pdi_aux->popular_pdi += 2;
                      }
                      else{
                        printf("\n\t\t\t\tPonto de interesse não encontrado!\n");
                      }
                      break;
                    }
                    if(hot != NULL){
                      printf("\n\t\t\t\tPonto Hot já definido! Por favor, remova primeiro.\n");
                      break;
                    }
                  }while(procura_pdi_fav(pdis_u, n) == 0);break;
                }
                else if (c == 'N' || c == 'n'){
                  fgets(n, SIZE, stdin);
                  aux3 = Pdis_pref;
                  do{
                    printf("\t\t\t\tInsira o nome do ponto de interesse:  ");
                    fflush(stdin);
                    fgets(n, SIZE, stdin);
                    n[strcspn(n, "\n")] = 0;
                    if(pdis_u == NULL){
                      Pdis_pref->pdi_aux->num = 0;
                      if (procura_pdi_fav(Pdis_pref, n) == 1){
                        printf("\n\t\t\t\tPonto de interesse encontrado!\n");
                        increm_pdi = procura_pdi(aux3, n);
                        pdis_u = faz_lista_lpdiu(pdis_u,increm_pdi);
                        (increm_pdi->pdi_aux->popular_pdi)++;
                        (Pdis_pref->pdi_aux->num)++;
                      }
                      else{
                        printf("\n\t\t\t\tPonto de interesse não encontrado!\n");
                      }
                      break;
                    }
                    r = procura_pdi_fav(pdis_u, n);
                    if(r==0){
                      if (procura_pdi_fav(Pdis_pref, n) == 1){
                        printf("\n\t\t\t\tPonto de interesse encontrado!\n");
                        increm_pdi = procura_pdi(aux3, n);
                        pdis_u = faz_lista_lpdiu(pdis_u,increm_pdi);
                        increm_pdi->pdi_aux->popular_pdi += 1;
                        (Pdis_pref->pdi_aux->num)++;
                      }
                      else{
                        printf("\n\t\t\t\tPonto de interesse não encontrado!\n");
                      }
                    }
                    else{
                      printf("Ponto de interesse já registado!");
                    }
                  }while(procura_pdi_fav(pdis_u, n) == 0);
                }
                else {
                  printf("\n\t\t\t\tCaracter inválido!\n");
                }
              }while (c != 'S' && c != 'c' && c != 'N' && c != 'n');break;
            }
            else {
              printf("\n\t\t\t\tCaracter inválido!\n");
            }
          }while(num != 1 && num != 2); break;
        }
        else if(c == 'R' || c == 'r'){
          printf("\n\n\t\t\t\tCIDADE.....................1\n\t\t\t\tPONTO DE INTERESSE.........2\n");
          printf("\n\t\t\t\tESCOLHA:\t");
          scanf("%d", &num);
          fflush(stdin);
          if (num == 1){
            fgets(n, SIZE, stdin);
            imprime_lista_cids(cids_u);
            printf("\n\t\t\t\tIntroduza a cidade que pretende remover:  ");
            fgets(n, SIZE, stdin);
            n[strcspn(n, "\n")] = 0;

            if (procura_cid_fav(cids_u, n) == 1){
              remove_cid = procura_cid(cids_u, n);
              remove_cids(remove_cid, n);
              printf("\n\t\t\t\tCidade removida com sucesso!");
            }
            else{
              printf("Cidade não encontrada!");
            }
          }
          if (num ==2){
            fgets(n, SIZE, stdin);
            if(pdis_u==NULL){
              printf("Lista vazia!");
              break;
            }
            else{
              imprime_lista_pdis_pref(pdis_u);
              printf("\n\t\t\t\tQUER REMOVER O PONTO HOT? (S/N)  ");
              scanf(" %c", &c);
              if (c == 'S' || c == 's'){
                remove_hot(hot);
                break;
              }
            else if (c == 'N' || c == 'n'){
              printf("\n\t\t\t\tIntroduza o ponto de interesse que pretende remover:  ");
              fgets(n, SIZE, stdin);
              fgets(n, SIZE, stdin);
              n[strcspn(n, "\n")] = 0;

              if (procura_pdi_fav(pdis_u, n) == 1){
                remove_pdi = procura_pdi(pdis_u, n);
                remove_pdis(pdis_u, n);
                printf("Ponto de interesse removido com sucesso!");
                break;
              }
              else{
                printf("Ponto de interesse não encontrado!");
              }
            }
            else{
              printf("Caracter inválido!");
            }
          }
        }
        else{
          printf("\n\t\t\t\tCaracter inválido!\n");
        }
      }
      }while(c != 'A' && c !='a' && c != 'R' && c != 'r');

      system("sleep 01");
      break;

      case 4:
      printf("\n\t\t\t\tA LISTAR AS SUAS PREFERÊNCIAS POR ORDEM DECRESCENTE DE POPULARIDADE...\n\n\n");
      if (cids_u == NULL && pdis_u != NULL && hot == NULL){
        printf("\t\t\t\tNão tem cidades registadas!\n");
        printf("\n\t\t\t\tPontos de  interesse:\n\n");
        imprime_lista_pdis_pref(pdis_u);
        printf("\n\t\t\t\tNão tem nenhum ponto hot registado!");
      }
      else if(cids_u != NULL && pdis_u == NULL && hot == NULL){
        printf("\t\t\t\tCidades:\n\n");
        imprime_lista_cids(cids_u);
        printf("\n\t\t\t\tNão tem pontos de interesse registados!\n");
        printf("\n\t\t\t\tNão tem nenhum ponto hot registado!");
      }
      else if(cids_u != NULL && pdis_u == NULL && hot != NULL){
        printf("\t\t\t\tCidades:\n\n");
        imprime_lista_cids(cids_u);
        printf("\n\t\t\t\tNão tem pontos de interesse registados!\n");
        printf("\n\t\t\t\tHot:\n\n");
        imprime_lista_pdis_pref(hot);
      }
      else if (cids_u != NULL && pdis_u != NULL && hot == NULL){
        printf("\t\t\t\tCidades:\n\n");
        imprime_lista_cids(cids_u);
        printf("\n\t\t\t\tPontos de  interesse:\n\n");
        imprime_lista_pdis_pref(pdis_u);
        printf("\n\t\t\t\tNão tem nenhum ponto hot registado!");
      }
      else if(cids_u == NULL && pdis_u != NULL && hot != NULL){
        printf("\t\t\t\tNão tem cidades registadas!\n");
        printf("\n\t\t\t\tPontos de  interesse:\n\n");
        imprime_lista_pdis_pref(pdis_u);
        printf("\n\t\t\t\tHot:\n\n");
        imprime_lista_pdis_pref(hot);
      }
      else if (cids_u != NULL && pdis_u == NULL && hot == NULL){
        printf("\t\t\t\tCidades:\n\n");
        imprime_lista_cids(cids_u);
        printf("\n\t\t\t\tNão tem pontos de interesse registados!\n");
        printf("\n\t\t\t\tHot:\n\n");
        imprime_lista_pdis_pref(hot);
      }
      else if(cids_u == NULL && pdis_u == NULL && hot != NULL){
        printf("\t\t\t\tNão tem cidades registadas!\n");
        printf("\n\t\t\t\tNão tem pontos de interesse registados!\n");
        printf("\n\t\t\t\tHot:\n\n");
        imprime_lista_pdis_pref(hot);
      }
      else if(cids_u != NULL && pdis_u != NULL && hot != NULL){
        printf("\t\t\t\tCidades:\n\n");
        imprime_lista_cids(cids_u);
        printf("\n\t\t\t\tPontos de  interesse:\n\n");
        imprime_lista_pdis_pref(pdis_u);
        printf("\n\t\t\t\tHot:\n\n");
        imprime_lista_pdis_pref(hot);
      }
      else{
        printf("\n\t\t\t\tNão tem dados para apresentar!\n");
      }

      printf("\n\t\t\t\t(Dê scroll caso necessário)");
      do{
        printf("\n\n\n\n\n\t\t\t\t(Prima 1 para sair)\t");
        scanf("%d", &num);
        if(num != 1){
          printf("\n\t\t\t\tValor inválido!\n");
        }
      }while(num != 1);
      break;

      case 5:
      printf("\n\t\t\t\tPREPARANDO A CONSTRUÇÃO...\n");
      if (lista_cids->num != 3)
      {
        printf("\n\t\t\t\tErro! Verifique se tem 3 cidade preferidas para construir a viagem!");
      }
      else{
        aux4 = cids_u;

        while(aux4 != NULL){
          printf("\n\t\t\t\tCidade - %s - com visita a:\n", aux4->nome);
          pesquisa_cid = aux4->lista_pdi;

          while(pdis_u != NULL){
            walker = pdis_u->pdi_aux;
            do{

              if(strcmp(pesquisa_cid->nome, walker->nome) == 0){
              printf("\n\t\t\t\t-> %s\n", walker->nome);
              }
              if (pesquisa_cid->prox == NULL){
                break;
              }
              pesquisa_cid = pesquisa_cid->prox;

            }while(pesquisa_cid->prox != NULL);
            pdis_u = pdis_u->prox;

          }

          aux4 = aux4->prox;

        }
        do{
          printf("\n\n\n\n\n\t\t\t\t(Prima 1 para sair)\t");
          scanf("%d", &num);
          if(num != 1){
            printf("\n\t\t\t\tValor inválido!\n");
          }
        }while(num != 1);
        break;
      }
      system("sleep 01");
      break;

      case 6:
      printf("\n\t\t\t\tOBRIGADO! ATÉ À PRÓXIMA!\n\n");
      system("sleep 01");
      break;

      default :
      printf ("\n\t\t\t\tVALOR INVÁLIDO!\n");
      system("sleep 01");
    }
    fclose(f);
    system("clear");
    printf("\n\n\n\t\t\t\t---------------------- (DEI)XA PLANEAR A TUA VIAGEM ------------------------\t\t\t\t\n\n\n");

  } while(num != 6);
}

void limpa(){
  int i;
  system("clear");
  printf("\n\n\t\tLoading");

  for(i=0;i < 4; i++){
  system("sleep 0.2");
  printf(".");
  fflush(stdout); // atualizar a tela
  }
  system("sleep 0.3");
  system("clear");
  printf("\n\n\n\t\t\t\t---------------------- (DEI)XA PLANEAR A TUA VIAGEM ------------------------\t\t\t\t\n\n\n");
}

Luser insere_Luser(Luser l, Luser novo){
  Luser act = l,ant=NULL;
  while(act)
  {
    ant = act;
    act = act ->prox;
  }
  novo->prox = act;
  if(ant==NULL){
    l=novo;
  }
  else{
    ant->prox=novo;
  }
  return l;
}

Luser faz_lista_users(Luser l,char nom[SIZE],char morad[SIZE],Data nas,char te[SIZE]){
  Luser novo;
  novo=(Luser)malloc(sizeof(User));
  strcpy(novo->nome,nom);
  strcpy(novo->morada,morad);
  novo->nasc.dia=nas.dia;
  novo->nasc.mes=nas.mes;
  novo->nasc.ano=nas.ano;
  strcpy(novo->tel,te);
  novo->prox=NULL;
  l=insere_Luser(l,novo);
  return l;
}

Luser le_user(Luser l){
  FILE *f;
  char nome[SIZE],tel[SIZE],morada[SIZE];
  Data nasc;
  int tamanho;
  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Registos.txt", "r");
  do{
    fflush(stdin);
    fscanf(f,"%s\n", nome);
    le_morada(f,morada);
    le_data(f,&nasc);
    fscanf(f, "%s\n", tel);
    l = faz_lista_users(l,nome,morada,nasc,tel);
  }while(!feof(f));
  if(NULL != f)
  {
    fseek(f,0,SEEK_END);
    tamanho = ftell(f);
  }
  if(0 == tamanho){
    return NULL;
  }
  fclose(f);
  return l;
}

int verifica_ficheiro(){

  FILE * f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Registos.txt", "r");
  fseek( f, 0, SEEK_END );
  int tam = ftell(f);
  fclose(f);
  return tam;
}

void le_data(FILE * f,Data * nasc){
  int d,i=0;
  char c;
  do
  {
    fscanf(f,"%d%c",&d,&c);
    switch(i){
      case 0:
      nasc->dia=d;
      break;
      case 1:
      nasc->mes=d;
      break;
      case 2:
      nasc->ano=d;
      break;
    }
    i++;
  }while(c!='\n' || i<2);
}

void le_morada(FILE *f, char morada[]){
  char c;
  int i=0;
  do{
    fscanf(f,"%c",&c);
    if(c!='\n'){
      morada[i]=c;
    }
    i++;
  }while(c!='\n');
}

void imprime_lista_pdis_pref(Ltodos Pdis_pref){
  int i = 1;
  do{
    printf("\t\t\t\t(%d) -> %s\n", i,Pdis_pref->pdi_aux->nome);
    Pdis_pref=Pdis_pref->prox;
    i++;
  }while(Pdis_pref != NULL);
}

void imprime_lista_users(Luser lista_users){
  do{
    printf("%s\n",lista_users->nome);
    lista_users=lista_users->prox;
  }while(lista_users != NULL);
}

Lcid imprime_lista_cids(Lcid cids_u){
  Lcid aux;
  Lpdi walkerPdi;
  aux = cids_u;
  int i=1;
  while(aux != NULL){
    printf("\n\t\t\t\t(%d) -> %s\t", i, aux->nome);
    walkerPdi = aux->lista_pdi;
    while (walkerPdi){
      printf("\n\t\t\t\t%s\t", walkerPdi->nome);
      walkerPdi = walkerPdi->prox;
    }
    aux = aux->prox;
    i++;
  }
  return aux;
}

Luser estrutura_user(Luser l){
  Luser novo;
  novo=(Luser)malloc(sizeof(User));
  strcpy(novo->nome,l->nome);
  strcpy(novo->morada,l->morada);
  novo->nasc.dia=l->nasc.dia;
  novo->nasc.mes=l->nasc.mes;
  novo->nasc.ano=l->nasc.ano;
  strcpy(novo->tel,l->tel);
  novo->prox=NULL;
  return novo;
}

void atualiza_fich_user(Luser lista_users){
  FILE *f;
  int i, j;
  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Registos.txt", "w");
  do{
    fprintf(f, "%s\n", lista_users->nome);
    fprintf(f,"%s\n", lista_users->morada);
    fprintf(f, "%d/%d/%d\n", lista_users->nasc.dia, lista_users->nasc.mes, lista_users->nasc.ano);
    fprintf(f, "%s\n", lista_users->tel);
    lista_users = lista_users->prox;
  }while (lista_users != NULL);
  fclose(f);
}

void atualiza_fich_cids(Lcid lista_cids){
  FILE *f;
  Lcid aux;
  int i = 20;
  Lpdi aux_pdi;
  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Cidades.txt", "w");
  aux=lista_cids;
  fprintf(f,"%d\n",aux->ncid);
  while(aux!=NULL){
    fprintf(f,"%d,",aux->npdi);
    fprintf(f,"%s,",aux->nome);
    fprintf(f,"%d\n",aux->popular_cid);
    aux_pdi=aux->lista_pdi;
    while(aux_pdi!=NULL){
      fprintf(f,"%s|",aux_pdi->nome);
      fprintf(f,"%s|", aux_pdi->desc);
      fprintf(f,"%02d|", aux_pdi->hori);
      fprintf(f,"%02d|", aux_pdi->mini);
      fprintf(f,"%02d|", aux_pdi->horf);
      fprintf(f,"%02d|", aux_pdi->minf);
      fprintf(f,"%d|\n", aux_pdi->popular_pdi);
      aux_pdi=aux_pdi->prox;
    }
    aux=aux->prox;
  }
}

Luser insere_sort(Luser l, Luser novo){
  Luser act = l,ant=NULL;
  while(act && strcmp(act->nome,novo->nome)<0)
  {
    ant = act;
    act = act ->prox;
  }
  novo->prox = act;
  if(ant==NULL){
    l=novo;
  }
  else{
    ant->prox=novo;
  }
  return l;
}

Lcid * insere_Lcid(Lcid * l, Lcid nova){

  Lcid act = *l,ant=NULL;
  if(act==NULL){
    *l=nova;
    return l;
  }
  while(act && strcmp(act->nome,nova->nome)<0)
  {
    ant = act;
    act = act ->prox;
  }
  nova->prox = act;

  if(ant != NULL){
    ant->prox=nova;
  }
  return l;
}

Lpdi * insere_Lpdi(Lpdi * li, Lpdi novo){
  Lpdi act = *li,ant=NULL;

  while(act && strcmp(act->nome,novo->nome)<0)
  {
    ant = act;
    act = act ->prox;
  }
  novo->prox = act;
  if(ant==NULL){
    *li=novo;
    return li;
  }
  else{
    ant->prox=novo;
  }
  return  li;
}

Lcid faz_lista_cids(Lcid * l,int ncids,int npdis,char nom[SIZE],int popular_cd){
  Lcid nova;
  nova=(Lcid)malloc(sizeof(Cid));
  nova->ncid=ncids;
  nova->npdi=npdis;
  strcpy(nova->nome,nom);
  nova->popular_cid=popular_cd;
  nova->lista_pdi=NULL;
  nova->prox=NULL;

  l=insere_Lcid(l,nova);
  return nova;
}

Lpdi faz_lista_pdis(Lpdi * li,char nom[],char des[],int hoi,int mii,int hof,int mif,int popular_pd,int j){
  Lpdi novo;
  novo=(Lpdi)malloc(sizeof(Pdi));
  strcpy(novo->nome,nom);
  strcpy(novo->desc,des);
  novo->hori=hoi;
  novo->mini=mii;
  novo->horf=hof;
  novo->minf=mif;
  novo->popular_pdi=popular_pd;
  novo->prox=NULL;
  li=insere_Lpdi(li,novo);
  return novo;
}

Lcid le_fich_cidpd(Lcid l,Lpdi li){
  FILE *f;
  Lcid current;
  Lpdi current_lpdi;
  char nomecid[SIZE];
  char nomepdi[SIZE];
  char desc[SIZE];
  int hori,mini,horf,minf,ncid,npdi,i,j,tamanho;
  int popular_pdi;
  int popular_cid;
  f = fopen("/Users/rafaelbaptista/Documents/Projeto PPP/Cidades.txt", "r");
  fscanf(f,"%d\n",&ncid);
  for (i=0;i<ncid;i++)
  {
    fscanf(f,"%d,%[^,],%d\n",&npdi,nomecid, &popular_cid);
    current=faz_lista_cids(&l,ncid,npdi,nomecid,popular_cid);
    for (j=0;j<npdi;j++)
    {
      fscanf(f,"%[^|]|%[^|]|%02d|%02d|%02d|%02d|%d|\n",nomepdi,desc,&hori,&mini,&horf,&minf,&popular_pdi);
      current_lpdi=faz_lista_pdis(&(current->lista_pdi),nomepdi,desc,hori,mini,horf,minf,popular_pdi,j);
    }
  }
  if(NULL != f)
  {
    fseek(f,0,SEEK_END);
    tamanho = ftell(f);
  }
  if(0 == tamanho){
    return NULL;
  }
  fclose(f);
  return l;
}

void imprime_bem(Lcid lista_cids){
  Lcid aux;
  Lpdi aux_pdi;
  int j;
  aux=lista_cids;
  while(aux!=NULL){
    printf("\n\t\t\t\t%s:\n\n",aux->nome);
    aux_pdi=aux->lista_pdi;
    j=0;
    while(aux_pdi!=NULL){
      printf("\t\t\t\t%-40s",aux_pdi->nome);
      printf("%-50s", aux_pdi->desc);
      printf("%02d : ", aux_pdi->hori);
      printf("%02d ", aux_pdi->mini);
      printf("- %02d : ", aux_pdi->horf);
      printf("%02d\n", aux_pdi->minf);
      aux_pdi=aux_pdi->prox;
      j++;
    }
    aux=aux->prox;
  }
}

Lcid procura_cid(Lcid lista_cids, char nome[]){
  Lcid aux = lista_cids;

  while (aux != NULL) {
    if (strcmp(aux->nome,nome) == 0){
      return aux;
    }
    else {
      aux = aux->prox;
    }
  }
  return NULL;
}

Ltodos procura_pdi(Ltodos lista_pdi, char nome[]){
  Ltodos aux;
  aux=lista_pdi;
  while(aux){
    if(strcmp(aux->pdi_aux->nome,nome)==0){
      return aux;
    }
    aux=aux->prox;
  }
  return NULL;
}

Luser procura_nome_user(Luser lista_user, char nome[]){
  Luser aux;
  aux=lista_user;
  while (strcmp(nome,aux->nome) != 0)
  {

    if (aux->prox != NULL)
    {
      aux=aux->prox;
    }
    else{
      return NULL;
    }
  }
  return aux;
}

Ltodos faz_lista_todos(Lcid lista_cids, Ltodos lis){
  int i,npdi;
  Ltodos novo;
  Lcid aux;
  Lpdi aux_pdi;
  aux = lista_cids;
  while (aux!=NULL){
    npdi = aux->npdi;
    aux_pdi = aux->lista_pdi;
    for (i=0;i<npdi;i++){
      novo=(Ltodos)malloc(sizeof(Todos_pdi));
      novo->pdi_aux=aux_pdi;
      lis = inserir_Ltodos(lis,novo);
      aux_pdi=aux_pdi->prox;
    }
    aux=aux->prox;
  }
  return lis;
}

Ltodos inserir_Ltodos(Ltodos lis, Ltodos novo){
  Ltodos act = lis,ant=NULL;

  while(act && act->pdi_aux->popular_pdi>novo->pdi_aux->popular_pdi)
  {
    ant = act;
    act = act ->prox;
  }
  novo->prox = act;
  if(ant==NULL){
    lis=novo;
    return lis;
  }
  else{
    ant->prox=novo;
  }
  return  lis;
}

Ltodos insere_pdiu(Ltodos lpdiu, Ltodos novo){
  Ltodos act = lpdiu,ant=NULL;
  while (act && act->pdi_aux->popular_pdi>novo->pdi_aux->popular_pdi)
  {
    ant = act;
    act = act ->prox;
  }
  novo->prox = act;
  if(ant==NULL){
    lpdiu=novo;
    return lpdiu;
  }
  else{
    ant->prox=novo;
  }
  return  lpdiu;
}

Ltodos faz_lista_lpdiu(Ltodos pdis_u, Ltodos increm_pd){
  Ltodos novo;
  novo=(Ltodos)malloc(sizeof(Todos_pdi));
  novo->pdi_aux=increm_pd->pdi_aux;
  pdis_u = insere_pdiu(pdis_u,novo);
  return pdis_u;
}

Lcid encontra_no(Lcid lista_cid, int num){
  Lcid aux;
  aux = lista_cid;
  while (num>1) {
    aux = aux->prox;
    num--;
  }
  return aux;
}

Lcid insere_cidu(Lcid lcidu, Lcid novo){
  Lcid act = lcidu,ant=NULL;
  int i;
  while (act)
  {
    ant = act;
    act = act->prox;
  }
  act = novo->prox;
  if(ant == NULL){
    lcidu=novo;
    return lcidu;
  }
  else{
    ant->prox=novo;
  }
  return  lcidu;
}

Lcid faz_lista_lcidu(Lcid cids_u, Lcid increm_cid){
  Lcid novo;

  Lpdi walker;
  novo=(Lcid)malloc(sizeof(Cid));
  strcpy(novo->nome,increm_cid->nome);
  novo->lista_pdi = (Lpdi)malloc(sizeof(Pdi));
  novo->lista_pdi = increm_cid->lista_pdi;
  novo->prox = NULL;
  cids_u = insere_cidu(cids_u,novo);
  return cids_u;
}

int procura_cid_fav(Lcid lista_cid, char nome[]){

  while (strcmp(nome,lista_cid->nome) != 0)
  {
    if (lista_cid->prox == NULL)
    {
      return 0;
    }
    else{
      lista_cid = lista_cid->prox;
    }
  }
  return 1;
}

int procura_pdi_fav(Ltodos lista_pdi, char nome[]){

  while (strcmp(nome,lista_pdi->pdi_aux->nome) != 0)
  {
    if (lista_pdi->prox == NULL)
    {
      return 0;
    }
    else{
      lista_pdi = lista_pdi->prox;
    }
  }
  return 1;
}

Lpdi procura_se_esta_na_cid(Lcid lista_cid, Lcid cids_u){
  Lpdi retorna = NULL;
  retorna = (Lpdi)malloc(sizeof(Pdi));
  Lcid aux;
  aux = lista_cid;
  while(aux != NULL){
      while (strcmp(aux->nome, cids_u->nome) == 0){
        retorna = copia_mem(retorna, aux);
        return retorna;
      }
      aux = aux->prox;
  }
    return NULL;
}

Lpdi copia_mem(Lpdi retorna, Lcid aux){
  strcpy(retorna->nome, aux->lista_pdi->nome);
  strcpy(retorna->desc, aux->lista_pdi->desc);
  retorna->hori = aux->lista_pdi->hori;
  retorna->mini = aux->lista_pdi->mini;
  retorna->horf = aux->lista_pdi->horf;
  retorna->minf = aux->lista_pdi->minf;
  retorna->popular_pdi = aux->lista_pdi->popular_pdi;
  retorna->num = aux->lista_pdi->num;
  return retorna;
}

void remove_cids(Lcid cids_u,char nome[]){
    Lcid aux = cids_u , temp;
    if(aux != NULL && (strcmp(aux->nome,nome)==0)){
        cids_u = aux -> prox;
        free(aux);
        return;
    }
    while (aux != NULL && (strcmp(aux->nome,nome)!=0)){
        temp = aux;
        aux = aux -> prox;
    }
    if (aux == NULL ){
        return;
    }
    temp -> prox = aux -> prox;
    free(aux);
}

Ltodos remove_hot(Ltodos hot){
  free(hot);
  return hot;
}

void remove_pdis(Ltodos Pdis_pref,char nome[]){
    Ltodos aux = Pdis_pref , temp;
    if (aux != NULL && (strcmp(aux->pdi_aux->nome,nome)==0)){
        Pdis_pref = aux->prox;
        free(aux);
        return;
    }
    while (aux != NULL && (strcmp(aux->pdi_aux->nome,nome)!=0)){
        temp = aux;
        aux = aux -> prox;
    }
    if(aux == NULL){
        return;
    }
    temp -> prox = aux -> prox;
    free(aux);
}

#endif /* compiling_error_h */
