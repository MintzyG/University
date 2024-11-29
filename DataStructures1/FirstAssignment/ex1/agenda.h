#pragma once

typedef struct Contacts Contacts;
typedef struct Person Person;
typedef enum Options Options;

struct Person{
  char *nome, *email;
  int telefone;
};

struct Contacts{
    Person* People;
    int size, capacity, t_limit;
  
    void (*ReallocPerson)(Contacts* self);
    void (*ShowContacts)(Contacts* self);
    void (*GenericSearch)(Contacts* self, void (*f)(Contacts*, int));
    void (*CreateContact)(Contacts* self);
    void (*Info)(Contacts* self);
};

enum Options {
    ADD = 1,
    EDIT,
    SHOW,
    REMOVE,
    SEARCH,
    INFO,
    QUIT,
};

void DeleteContact(Contacts*, int);
void Place(Contacts*, int);
Contacts* InitiateContacts();
