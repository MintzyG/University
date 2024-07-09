#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "VectorUtility.h"
#include <sys/ioctl.h>
#include <unistd.h>

void DrawGraph(int*, int, int, int);

void ShowVectorPaddingCustom(int* vector, int size, int width, int block_size) {
    printf("\n");

    printf(" %*s", (block_size + 1)/2, " ");
    for (int i = 0; i < size; i++) {
        printf("%d%*s", vector[i], block_size-1, " ");
    }
}


void Swap(int* vector, int index_a, int index_b){
    *(vector+index_a) = *(vector+index_a) + *(vector+index_b) - (*(vector+index_b) = *(vector+index_a));
}


void SetBlockSize(int* block_size, int cols, int keys) {
    *block_size = ((cols - (keys + 1)) / keys);
}

void DrawBlock(int block_size, int state) {

    if (state == 0)
        for (int i = 0; i < block_size; i++)
            printf("█");
    else
        for (int i = 0; i < block_size; i++)
            printf(" ");
    

}

void DrawGraph(int* vector, int keys, int block_size, int height) {
    for (int i = height; i > 0; i--){
        printf(" ");
        for (int j = 0; j < keys; j++){
            if (i <= vector[j]) {
                DrawBlock(block_size, 0);
            } else {
                DrawBlock(block_size, 1);
            }
            printf(" ");
        }
        if (i > 1)
            printf("\n");
    }
}

void QuickSort(int* vector, int first, int last, struct winsize w, int keys, int block_size, char** argv) {
    if (last - first < 2)
        return;
  
    int pivot = vector[first];
    int pointer_b = last - 1 /*, pointer_a = start*/;
    int swap_marker = last;
    
    for (int i = pointer_b; i >= first; i--)
        if (vector[i] >= pivot) {
            swap_marker--; 
            if (i < swap_marker)
                Swap(vector, i, swap_marker);
        } 
  
    // Used for drawing each step to console
    if(atoi(argv[2]) != 0) {
        DrawGraph(vector, keys, block_size, w.ws_row);
        ShowVectorPaddingCustom(vector, keys, w.ws_col, block_size);
        getchar();
    }
    
    QuickSort(vector, first, swap_marker, w, keys, block_size, argv);
    QuickSort(vector, swap_marker+1, last, w, keys, block_size, argv);
    
}

int main(int argc, char** argv) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int max_partition = 0;

    if(atoi(argv[2]) > 0 || atoi(argv[2]) < 0) {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 30) {
            printf("Invalid Argument");   
            exit(1);
        }
        max_partition = w.ws_row;
    } else {
        max_partition = atoi(argv[3]);
        if (max_partition <= 0 || max_partition > 1000)
            max_partition = 500;
    }

    int block_size = 0;
    int keys = atoi(argv[1]);
    SetBlockSize(&block_size, w.ws_col, keys);

    srand(time(NULL));
    int size = atoi(argv[1]);
    int* vector = CreateVector(size);    
    PopulateVector(vector, size, max_partition);

    if (atoi(argv[2]) != 0) {
        DrawGraph(vector, keys, block_size, w.ws_row);
        ShowVectorPaddingCustom(vector, size, w.ws_col, block_size);
    }

    QuickSort(vector, 0, size, w, keys, block_size, argv);
    
    if (atoi(argv[2]) != 0)
        DrawGraph(vector, keys, block_size, w.ws_row);
    
    ShowVectorPaddingCustom(vector, size, w.ws_col, block_size);
    return 0;
}
