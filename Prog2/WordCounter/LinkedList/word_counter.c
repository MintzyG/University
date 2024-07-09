#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char letter;
  int amount;
  struct Node* prox;
} Node;  

typedef struct List {
  int amount;
  Node* first;
  Node* last;
}List;

Node* createNode(char letra){
  Node* node = (Node*)malloc(sizeof(Node));
  node->letter = letra;
  node->amount = 1;
  node->prox = NULL;
  return node;
}

void AddElement(char letra, List *lst) {
  Node *node, *last, *new;
  last = NULL;
  node = lst->first;
  if(!node) { lst->first = createNode(letra); lst->amount +=1; return; }

  do{
    if(node->letter == letra) { node->amount +=1; break; }

    if(letra < node->letter) {
      new = createNode(letra);
      new->prox = node;
      lst->amount += 1;
      if (last) { last->prox = new; }
      else { lst->first = new; }
      break;
    }

    last = node;
    node = node->prox;
    } while (node);

    if(!node) {
      new = createNode(letra);
      new->prox = node;
      lst->amount += 1;
      if(last) { last->prox = new; }
    }
}

void ShowList(Node* node){
  while (node) {
    printf("%c: %d\n", node->letter, node->amount);
    node = node->prox;
  }
}

void SortList(List* myList){
  if (myList->first == NULL) {
    return;
  }

  Node* dummy = createNode('0');
  Node* node = myList->first;
  Node* last = dummy;
  Node* next = NULL;
  while (node != NULL) {
    next = node->prox;
    while (last->prox != NULL &&  last->prox->amount < node->amount) {
      last = last->prox;
    }
    node->prox = last->prox;
    last->prox = node;
    last = dummy;
    node = next;
  }

}

int main() {

  FILE *arquivo;
  arquivo = fopen("text.txt", "r");
  if(!arquivo) {
    printf("Couldn't open file");
    exit(1);
  }

  List myList;
  myList.first = NULL;
  myList.last = NULL;

  char letra;
  while((letra = fgetc(arquivo)) != EOF) {
    AddElement(letra, &myList);
  }

  fclose(arquivo);
 
  printf("Lista\n");
  ShowList(myList.first);

  printf("Ordenando lista\n");
  SortList(&myList);
  ShowList(myList.first);

  return 0;
}
