// ------------------------------------------------------------- //
//  Copyright - Sophia Hoffmann - UENF - 2024                    //
//  Participação especial: O GRANDIOSO EMANUEL*                  //
//  Aula: Estruturas de Dados e Algoritmos 1 - CCT - LCMAT - CC  //
//  Professor: Fermin Alfredo Tang Montané                       //
// ------------------------------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int choice = 0;
  Head* H = CreateHead();

  while ((Choice)choice != QUIT) {
    printf("1: CREATE\n2: PRINT USER\n3: COMPARE\n");
    printf("4: SHOW LIST\n5: DELETE USER\n6:QUIT\nOpcao: ");
    scanf("%d[^\n]", &choice);
    scanf("%*c");
    puts("-------------------------------");
    switch((Choice)choice) {
      case CREATE:
        H->CreateNode(H);
        break;
      case PRINT:
        H->FindUser(H);
        break;
      case COMPARE:
        H->CompareNode(H);
        break;
      case SHOW:
        H->PrintAll(H);
        break;
      case DELETE:
        H->DeleteNode(H);
        break;
      case QUIT:
        break;
      default:
        continue;
    }
    puts("-------------------------------");
  }
  return 0;
}
