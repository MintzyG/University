#include "olytics.h"
#include "obase.h"
#include "helpers.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void* OlyticsWrapper(OlyticsInstance* O, void* (*function)(void* ptr, int size, int* cmp, int* swp, int* ops), void* data, int size) {
  O->logs->Log(O->logs, "Creating Probe", __func__, TRACE);
  Probe* P = O->NewProbe();

  O->logs->Log(O->logs, "Creating data points", __func__, TRACE);
  int *cmp, *swp, *ops;
  cmp = (int*)calloc(1, sizeof(int));
  swp = (int*)calloc(1, sizeof(int));
  ops = (int*)calloc(1, sizeof(int));

  O->logs->Log(O->logs, "Starting testing", __func__, WARN);
  P->ProbeStartClock(P);

  function(data, size, cmp, swp, ops);

  P->ProbeEndClock(P);
  P->ExecutionTime(P);
  O->logs->Log(O->logs, "Finished testing", __func__, WARN);

  if (O->logs->log_level == ALL) {
    printf("\n\n Got data back: \ncmp:%d\nops:%d\nswap:%d\n", *cmp, *ops, *swp);
  }

  O->logs->Log(O->logs, "Registering data", __func__, TRACE);
  P->RegisterData(P, ops, cmp, swp);

  O->obase->AddProbe(O->obase, P);

  O->logs->Log(O->logs, "Freeing data points", __func__, TRACE);
  free(cmp);
  free(swp);
  free(ops);

  return data;
}

void ProbeDataByIndex(OlyticsInstance* O, int index) { 
  O->obase->database[index].ProbeData(&O->obase->database[index]);
}

void GenerateTestData(OlyticsInstance* O, int amount, int ceiling) {
  O->logs->Log(O->logs, "Allocating test data array", __func__, TRACE);
  int* ptr = calloc(amount, sizeof(int));
  if (!ptr) {
    printf("Couldn't allocate enough memory for test data");
    exit(1);
  }

  if (O->logs->log_level == ALL) {
    printf("%s: Following is the empty array:\n", __func__);
      for (int i = 0; i < amount; i++) {
        printf("%d ", ptr[i]);
      }
      printf("\n\n");
  }

  O->logs->Log(O->logs, "Generating test data", __func__, ALL);
  for (int i = 0; i < amount; i++) {
    ptr[i] = rand() % ceiling + 1;
  }

  if (O->logs->log_level == ALL) {
    printf("%s: Following is the generated data:\n", __func__);
      for (int i = 0; i < amount; i++) {
        printf("%d ", ptr[i]);
      }
      printf("\n\n");
  }

  O->testData = ptr;
}

int* GetTestData(OlyticsInstance* O) {
  int* ptr = (int*)calloc(O->dataSize, sizeof *ptr);
  memcpy(ptr, O->testData, O->dataSize * sizeof *ptr);
  return ptr;
}

OlyticsInstance* CreateInstance() {
  OlyticsInstance* O = (OlyticsInstance*)calloc(1, sizeof(OlyticsInstance));
  *O = (OlyticsInstance) {
    .NewProbe = NewProbe,
    .obase = CreateDB(),
    .OlyticsWrapper = OlyticsWrapper,
    .ProbeDataByIndex = ProbeDataByIndex,
    .logs = InitLog(),
    .GenerateTestData = GenerateTestData,
    .GetTestData = GetTestData,
    .testData = (int*)calloc(1, 4),
    .dataSize = 1,
    .dataCeiling = 1,
  };
  return O;
}
