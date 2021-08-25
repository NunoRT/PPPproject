//
//  main.c
//  Projeto
//
//  Created by Nuno Tiago on 24/04/2019.
//  Copyright © 2019 Nuno Tiago. All rights reserved.
//
#include "header.h"

int main(){
  Luser headuser = NULL;
  headuser = (Luser)malloc(sizeof(User));
  Luser lista_users = NULL;
  lista_users = le_user(lista_users);
  Lpdi lista_pdi = NULL;
  Lcid lista_cids = NULL;
  Lcid cids_u = NULL;
  Lpdi pdis_u = NULL;
  lista_cids = le_fich_cidpd(lista_cids,lista_pdi);
  Ltodos Pdis_pref = NULL;
  Pdis_pref = faz_lista_todos(lista_cids, Pdis_pref);

  FILE *f;
  char c;
  printf("\n\n\n\t\t\t\t---------------------- (DEI)XA PLANEAR A TUA VIAGEM ------------------------\t\t\t\t\n\n\n");

  do {
    printf("\t\t\t\tREGISTO OU LOGIN? (R/L)\t");
    scanf(" %c", &c);

    if (c == 'R'|| c == 'r'){
      fazregisto(lista_users);
      limpa();
      fazlogin(lista_users, lista_cids, Pdis_pref);
      break;
    }

    else if (c == 'L'|| c == 'l'){
      fazlogin(lista_users, lista_cids, Pdis_pref);
      break;
    }
    else {
      printf("\t\t\t\tCaracter inválido!\n");
    }
  } while (c != 'R' || c != 'L');

  atualiza_fich_user(lista_users);
  atualiza_fich_cids(lista_cids);
  system("clear");
  printf("\n\n\n\t\t\t\t---------------------- (DEI)XA PLANEAR A TUA VIAGEM ------------------------\t\t\t\t\n\n\n");
  printf("\t\t\t\tWork by Nuno Tiago & Rafael Baptista\n\n\n");
  return 0;
}
