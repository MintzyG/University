#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "probe.h"

clock_t ProbeStartClock(Probe *probe) {
  clock_t start = clock();
  probe->startClock = start;
  return start;
}

clock_t ProbeEndClock(Probe *probe) {
  clock_t end = clock();
  probe->endClock = end;
  return end;
}

double ExecutionTime(Probe *probe) {
  double totalTime = ((double)(probe->endClock - probe->startClock)) / CLOCKS_PER_SEC;
  probe->executionTime = totalTime;
  return totalTime;
}

void RegisterData(Probe *probe, int* ops, int* comps, int* swaps) {
  probe->comparissons = *comps;
  probe->swaps = *swaps;
  probe->operations = *ops;
}

void ProbeData(Probe *probe) {
  printf("\n\nResults Stores in Probe %d\n", probe->id);
  printf("Program Executed in: %f seconds\n", probe->executionTime);
  printf("%d Comparissons were done\n", probe->comparissons);
  printf("%d Swaps were done\n", probe->swaps);
  printf("%d Operations were done\n\n", probe->operations);
}

Probe* NewProbe() {
  Probe* p = (Probe*)calloc(1, sizeof(Probe));
  *p = (Probe) {
    .comparissons = 0,
    .operations = 0,
    .swaps = 0,
    .executionTime = 0,
    .endClock = 0,
    .startClock = 0,
    .ProbeStartClock = ProbeStartClock,
    .ProbeEndClock = ProbeEndClock,
    .ExecutionTime = ExecutionTime,
    .RegisterData = RegisterData,
    .ProbeData = ProbeData,
    .id = 0
  }; 
  return p;
}
