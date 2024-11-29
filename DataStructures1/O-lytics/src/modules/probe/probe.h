#pragma once

#include <time.h>

typedef struct Probe Probe;

struct Probe {
    int operations, comparissons, swaps;
    clock_t startClock, endClock;
    double executionTime;

    clock_t (*ProbeStartClock)(Probe *self);
    clock_t (*ProbeEndClock)(Probe *self);
    double (*ExecutionTime)(Probe *self);

    int id;

    void (*RegisterData)(Probe *self, int* operations, int* comparissons, int* swaps);
    void (*ProbeData)(Probe *self);
};

Probe* NewProbe();
