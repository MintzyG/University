#pragma once

typedef struct List List;
typedef struct Head Head;
typedef enum Choice Choice;

enum Choice {
  CREATE = 1,
  PRINT,
  COMPARE,
  SHOW,
  DELETE,
  QUIT,
};

struct List {
  int ID;
  float CR;
  char* Name;
  List* next;
};

struct Head {
  List* first;
  int amount;

  void (*PrintAll)(Head*);
  void (*DeleteNode)(Head*);
  void (*PrintNode)(List*);
  void (*CreateNode)(Head*);
  void (*FindUser)(Head*);
  
  int (*CompareNode)(Head*);
};

Head* CreateHead();