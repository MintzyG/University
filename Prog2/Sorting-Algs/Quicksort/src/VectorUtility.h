#pragma once

#ifdef DEBUG
    void PopulateVectorDebug(int*, int, int, int);
    int* CreateVectorDebug(int, int);
#endif

void PopulateVector(int*, int, int);
int* CreateVector(int);
void ShowVector(int*, int, int, int);

#ifdef DEBUG
    #define PopulateVector(A, B, C) PopulateVectorDebug(A, B, C, __LINE__)
    #define CreateVector(A) CreateVectorDebug(A, __LINE__)
#endif
