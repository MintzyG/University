#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"
#define MAX_NAME_SZ 40

void ReallocPerson(Contacts* self) {
  Person* tmp = (Person*)calloc(self->size * 2, sizeof *tmp);
  memcpy(tmp, self->People, self->size * sizeof *tmp);
  self->People = tmp;
  self->size *= 2;
  self->capacity = self->size / 2;
}

void GetInput(char* name) {
    fgets(name, MAX_NAME_SZ, stdin);
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';
}

void PrintContact(Person self, int i) {
  printf("Contato %d:\n\tNome:%s\n\tEmail:%s\n\tTelefone:%d\n", i + 1, self.nome, self.email, self.telefone);
}

void ShowContacts(Contacts* self){
  for (int i = 0; i < self->size; i++)
    PrintContact(self->People[i], i);
}

void Place(Contacts* self, int index) {
  char *nome, *email;
  nome = (char*)calloc(40, 1);
  email = (char*)calloc(40, 1);
  int telefone = 0;

  printf("Nome: ");
  GetInput(nome);
  self->People[index].nome = nome;

  printf("email: ");
  GetInput(email);
  self->People[index].email = email;

  printf("Telefone: ");
  scanf("%d[^\n]", &telefone);
  scanf("%*c");
  self->People[index].telefone = telefone;
}

void CreateContact(Contacts* self){
  if (self->capacity == 0) { ReallocPerson(self); }
  int index = self->size - self->capacity;
  printf("Criando contato por favor digite as informacoes:\n");   
  Place(self, index);
  self->capacity -= 1;
}

void DeleteContact(Contacts* self, int index){
  self->People[index] = self->People[self->size - self->capacity - 1];
  self->People[self->size - self->capacity - 1].nome = NULL;
  self->People[self->size - self->capacity - 1].email = NULL;
  self->People[self->size - self->capacity - 1].telefone = 0;
  self->capacity += 1;
}

int LoopSearch(Contacts* self, char* name, char* email, int* number, int* counter) {
  int index = 0;
  for (int i = 0; i < self->size - self->capacity; i++){
    if (name != NULL && email == NULL && number == NULL) {
      if (!strcmp(self->People[i].nome, name)) {
        PrintContact(self->People[i], i);
        if (counter != NULL) { 
          (*counter)++; 
          index = i;
        }
      }
    } else if (name == NULL && email != NULL && number == NULL) {
      if (!strcmp(self->People[i].email, email)) {
        PrintContact(self->People[i], i);
        if (counter != NULL) { 
          (*counter)++; 
          index = i;
        }
      }
    } else if (name == NULL && email == NULL && number !=  NULL) {
      if (self->People[i].telefone == *number) {
        PrintContact(self->People[i], i);
        if (counter != NULL) { 
          (*counter)++; 
          index = i;
        }
      }
    } else if (name != NULL && email != NULL && number == NULL) {
      if (!strcmp(self->People[i].nome, name) && !strcmp(self->People[i].email, email)){
        PrintContact(self->People[i], i);
        if (counter != NULL) { 
          (*counter)++; 
          index = i;
        }
      }
    } else if (name != NULL && email != NULL && number != NULL) {
      if (!strcmp(self->People[i].nome, name) && !strcmp(self->People[i].email, email) && self->People[i].telefone == *number){
        PrintContact(self->People[i], i);
        if (counter != NULL) { 
          (*counter)++; 
          index = i;
        }
      }
    }
  }
  return index;
}

void GenericSearch(Contacts* self, void (*func)(Contacts* self, int index)){
  int counter = 0;
  int index = 0;
  char* nome = calloc(40, 1);
  char* email = calloc(40, 1);
  int telefone = 0;
  printf("Digite o nome da pessoa: ");
  GetInput(nome);
  index = LoopSearch(self, nome, NULL, NULL, &counter);

  if (counter == 0) {
    return;
  } else if (counter == 1) {
    printf("------------USANDO O SELECIONADO------------\n\n");
    PrintContact(self->People[index], index);
    if (func != NULL) { func(self, index); }
    return;
  }
  printf("Muitos usuarios com esse nome por favor digite o email.\n");
  counter = 0;

  printf("Digite o email da pessoa: ");
  GetInput(email);
  index = LoopSearch(self, nome, email, NULL, &counter);

  if (counter == 0) {
    return;
  } else if (counter == 1) {
    printf("------------USANDO O SELECIONADO------------\n\n");
    PrintContact(self->People[index], index);
    if (func != NULL) { func(self, index); }
    return;
  }

  printf("Muitos usuarios com esse nome e email por favor digite o telefone.\n");
  counter = 0;
  printf("Telefone: ");
  scanf("%d[^\n]", &telefone);
  scanf("%*c");
  index = LoopSearch(self, nome, email, &telefone, &counter);

  if (counter == 0) {
    return;
  } else if (counter == 1) {
    printf("------------USANDO O SELECIONADO------------\n\n");
    PrintContact(self->People[index], index);
    if (func != NULL) { func(self, index); }
    return;
  } else {
    printf("\n\nMULTIPLOS USUARIOS IDENTICOS DETECTADOS\n");
    printf("------------USANDO O ULTIMO------------\n\n");
    PrintContact(self->People[index], index);
    if (func != NULL) { func(self, index); }
    return;
  }
}

void Info(Contacts* self){
  printf("Agenda\ntamanho: %d\ncapacidade: %d\n", self->size, self->capacity);
}

Person* CreateList() {
  Person* P = (Person*)calloc(1, sizeof(Person));
  *P = (Person) {
    .nome = (char*)calloc(40, 1),
    .email = (char*)calloc(40, 1),
    .telefone = 0,
  };
  return P;
}

Contacts* InitiateContacts() {
  Contacts* A = (Contacts*)calloc(1, sizeof(Contacts)); 
  *A = (Contacts) {
    .People = CreateList(),
    .ShowContacts = ShowContacts,
    .GenericSearch = GenericSearch,
    .CreateContact = CreateContact,
    .Info = Info,
    .size = 1,
    .capacity = 1,
    .t_limit = 40,
  }; 
  return A;
}
