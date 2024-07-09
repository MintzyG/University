#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG

    void PopulateVectorDebug(int* vector, int size, int max_value, int line) {
        int amount = 0;
        for (int i = 0; i < size; i++) {
            vector[i] = rand() % max_value;  
            amount++;
        }  
        printf("\nDEBUG -- PopulateVector | [INSERTED %d VALUES AT LINE %d] -- DEBUG\n", amount, line);
    }
    
    int* CreateVectorDebug(int size, int line) {
        int* vector;
        vector = (int*)malloc(size * sizeof(int));
        printf("\nDEBUG -- [VECTOR ALLOCATED AT LINE %d] -- DEBUG\n", line);
        return vector;
    }

#endif

void ShowVector(int* vector, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", vector[i]);
} 

void PopulateVector(int* vector, int size, int max_value) {
    for (int i = 0; i < size; i++)
        vector[i] = rand() % max_value;  
}

int* CreateVector(int size) {
    int* vector;
    vector = (int*)malloc(size * sizeof(int));
    return vector;
}

#ifdef DEBUG
    #define PopulateVector(A, B, C) PopulateVectorDebug(A, B, C, __LINE__)
    #define CreateVector(A) CreateVectorDebug(A, __LINE__)
#endif

