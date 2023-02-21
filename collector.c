#include<stdio.h>
#include<stdlib.h>
#include "collector.h"




void heap_allocate(int size, Collector *collector){
    if(size > collector->heapSize - collector->bumpPointer){
        printf("Error, cannot allocate memory as it goes out of bounds\n");
        return;
    }
    int currPointer = collector->bumpPointer;
    collector->bumpPointer = currPointer + size;
    printf("[ Current offset: %d ]\n", collector->bumpPointer);
    int usedMemory = collector->bumpPointer;
    int freeMemory = collector->heapSize - usedMemory;

    printf("[ Used memory = %d, Free Memory = %d ]\n", usedMemory, freeMemory);
    
}

void heap_clear(Collector *collector){
    collector->bumpPointer = 0;
    printf("[ Cleared current memory, free memory now stands at %d ]\n", collector->heapSize);
}


void initialize(int totalSize, Collector *collector){
    collector->bumpPointer = 0;
    collector->heapSize = totalSize;
    // collector->heap = malloc(sizeof(char)*collector->heapSize);
    printf("[ Initialized a heap with size %d ]\n", totalSize);
}

void destroy(Collector *collector){
    free(collector->heap);
    collector->heapSize = 0;
    printf("[ Cleared the contents of the heap and freed the memory to prevent memory leaks ]");
}