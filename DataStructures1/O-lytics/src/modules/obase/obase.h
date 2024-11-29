#pragma once

#include "probe.h"

typedef struct Obase Obase;

struct Obase {
  Probe* database;
  int capacity, size;

  void (*ResizeDatabase)(Obase* O);
  Probe* (*AddProbe)(Obase* O, Probe* probe);
  void (*RemoveProbe)(Probe* probe);
};

Obase* CreateDB();
