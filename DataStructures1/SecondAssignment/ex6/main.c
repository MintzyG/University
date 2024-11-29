#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"
#include "list.h"

int main() {
  int menu = 0;
  Polynomials* list = CreatePoly();
  Head* polynomial = NULL;

  system("clear");
  while ((enum Menu)menu != QUIT) {
    printf("--- Recent polynomial ---\n");
    ShowPoly(polynomial);
    printf("--- List ---\n");
    ShowList(list);
    printf("--- MENU ---\n");
    printf("1: Create\n2: Add to List\n");
    printf("3: Remove from List\n4: Sum polynomials\n");
    printf("5: Quit\nOption: ");
    scanf("%d[^\n]", &menu);
    scanf("%*c");

    switch((enum Menu)menu) {
      case CREATE:
        polynomial = CreateList();
        CreatePolynomial(polynomial);
        system("clear");
        break;
      case LIST_ADD:
        PushPoly(list, polynomial);
        system("clear");
        break;
      case LIST_RM:
        system("clear");
        PopPoly(list);
        system("clear");
        break;
      case SUM:
        system("clear");
        polynomial = SumPoly(list);
        system("clear");
        break;
      case QUIT:
        break;
      default:
        continue;
    }
  }
  return 0;
}
