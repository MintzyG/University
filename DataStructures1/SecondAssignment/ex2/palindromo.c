#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // tamanho máximo da string

typedef struct {
  int qtd;
  char *caracter;
} Pilha;

Pilha* CriarPilha(){
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
  if(pi != NULL){
    pi->qtd = 0;
    pi->caracter = (char *) malloc(MAX * sizeof(char));
    if (pi->caracter == NULL) {
      free(pi);
      pi = NULL;
    }
  }
  return pi;
}

void LiberarPilha(Pilha *pi){
  if(pi != NULL){
    if(pi->caracter != NULL){
      free(pi->caracter);
    }
    free(pi);
  }
}

void InserePilha(Pilha* p, char carac) {
  if (p->qtd < (MAX - 1)) {
    p->caracter[++(p->qtd)] = carac;
  } else {
    printf("Ultrapassou o tamanho máximo\n");
  }
}

char TiraPilha(Pilha* p) {
  if (p->qtd) {
    return p->caracter[(p->qtd)--];
  } else {
    printf("Não tem mais elementos na pilha\n");
    return '\0'; // caractere NULL
  }
}

char RemoverAcento(char c) {
  char *comAcento = "áàâãéèêíìîóòôõúùûçÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇ";
  char *semAcento = "aaaaeeeiiioooouuucAAAAEEEIIIOOOOUUUC";

  for (int i = 0; comAcento[i] != '\0'; i++) {
    if (c == comAcento[i]) {
      return semAcento[i];
    }
  }
  return c;
}

int Palindromo(char* str) {
  int Tam = strlen(str);
  Pilha *p = CriarPilha();

  char LStr[Tam];
  int LTam = 0;


  // limpa a string
  int i = 0;
  while(i < Tam) {
    if (isalnum(str[i])) {
      LStr[LTam++] = tolower(str[i]);
    } else {
      if(isalnum(RemoverAcento(str[i]))) {
        LStr[LTam++] = tolower(RemoverAcento(str[i]));
        i += 1; // se for caractere com acento, pula dois indices do vetor
      }
    }
    i += 1;
  }

  // insere os valores na pilha de comparação
  for (int i = 0; i < LTam; i++) {
    InserePilha(p, LStr[i]);
  }

  // verifica se a primeira pilha é igual a segunda
  for (int i = 0; i < LTam; i++) {
    if (TiraPilha(p) != LStr[i]) {
      return 0;
    }
  }
  return 1;
}

int main(){
  printf("\e[1;1H\e[2J"); // clear universal
  char frase[] = "adias a data da saída";

    if (Palindromo(frase)) {
      printf("\"%s\" é um palíndromo\n", frase);
    } else {
      printf("\"%s\" não é um palíndromo\n", frase);
    }
}
