#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "conjunto.h"

int main() {
  srand(time(NULL));

  Conjunto* CA = CreateConjunto();
  Conjunto* CB = CreateConjunto();

  CA->id = 1;
  CB->id = 2;

  CA->InsertElement(CA, 70);
  CA->InsertElement(CA, 0);
  CB->InsertElement(CB, 70);

  for (int i = 0; i < 9; i++) { CA->InsertElement(CA, i+1); }
  for (int i = 6; i < 12; i++) { CB->InsertElement(CB, i+1); }
  CA->InsertElement(CA, 4);
  CA->ShowElements(CA);
  CB->ShowElements(CB);

  printf("\n\nInsercoes finalizdas\n\n");

  CA->RemoveElement(CA, 70);
  CA->RemoveElement(CA, 4);
  CA->ShowElements(CA);

  CA->ContainsElement(CA, 4);
  CA->ContainsElement(CA, 29);
  CA->ContainsElement(CA, 3);

  printf("\n\nQuestions\n\n");

  CA->Info(CA);
  CB->Info(CB);
  printf("\n\n");

  Conjunto* U = CA->Union(CA, CB);
  Conjunto* I = CA->Intersection(CA, CB);

  U->ShowElements(U);
  I->ShowElements(I);

  // Era pra fazer a uniao disjuntiva ou nao?
  Conjunto* R = U->Difference(U, I);
  Conjunto* T = CA->Difference(CA, CB);
  printf("Smallest: %d\nBiggest: %d\n", R->GetSmallest(R), R->GetBiggest(R));

  if(CA->AssertEquals(CA, CB)){
    printf("Is equal\n");
  } else {
    printf("Not equal!\n");
  } 
  CA->ShowElements(T);
  R->ShowElements(R);
  if(R->AssertEquals(R, T)){
    printf("Is equal\n");
  } else {
    printf("Not equal!\n");
  }

  FreeConjunto(CA);
  FreeConjunto(CB);
  FreeConjunto(U);
  FreeConjunto(I);
  FreeConjunto(R);
  FreeConjunto(T);

  return 0;
}
