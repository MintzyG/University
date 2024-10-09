#include "obase.h"
#include "helpers.h"

#include <stdlib.h>
#include <string.h>

void ResizeDatabase(Obase* O) {
  printf("Resizing the DB\n");
  Probe* tmp = (Probe*)calloc(O->size * 2, sizeof *tmp);
  memcpy(tmp, O->database, O->size * sizeof *tmp);

  O->database = tmp;
  printf("Free tmp\n");

  O->size *= 2;
  printf("New size is %d\n", O->size);
  O->capacity = O->size/2;
  printf("New cap is %d\n", O->capacity);
}

Probe* AddProbe(Obase* O, Probe* probe) {
  printf("cur cap is %d\n", O->capacity);
  if (O->capacity >= 1) {
    for (int i = 0; i < O->size; i++) {
      if (O->database[i].id == 0) {
        printf("Found slot at pos %d\n", i);
        O->database[i] = *probe;
        O->database[i].id = i + 1;
    printf("Added probe of id(%d)\n", O->database[i].id);
        O->capacity -= 1;
        break;
      }
    }
    return probe;
  }

  ResizeDatabase(O);
  AddProbe(O, probe);
}

void RemoveProbe(__attribute__((unused))Probe *probe) {
  Uninplemented(__func__);
}

// Why does initializing to a pointer using compound literals doens't initialize some variables?
// So I have to resort to calloc then use compound.
// Can compound literals even be used to allocate memory?
Obase* CreateDB() {
  Obase* db = (Obase*)calloc(1, sizeof(Obase));
  *db = (Obase) {
    .database = (Probe*)calloc(1, sizeof(Probe)),
    .ResizeDatabase = ResizeDatabase,
    .AddProbe = AddProbe,
    .RemoveProbe = RemoveProbe,
    .capacity = 1,
    .size = 1,
  };
  return db;
}
