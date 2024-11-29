#pragma once
#include <time.h>
#include "obase.h"
#include "probe.h"
#include "helpers.h"

typedef struct OlyticsInstance OlyticsInstance;

struct OlyticsInstance {
  Obase* obase;
  // void* (functions[10])(void* ptr, int* cmp, int* swp, int* ops);

  oLog* logs;

  int* testData;
  int dataSize, dataCeiling;

  Probe* (*NewProbe)();
  void* (*OlyticsWrapper)(OlyticsInstance* O,void* (*function)(void* ptr, int size, int* cmp, int* swp, int* ops), void* data, int size);
  void (*ProbeDataByIndex)(OlyticsInstance* O, int index);
  void (*GenerateTestData)(OlyticsInstance* O, int amount, int ceiling);
  int* (*GetTestData)(OlyticsInstance* O);
};

OlyticsInstance* CreateInstance();
