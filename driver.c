#include<stdio.h>
#include<stdlib.h>
#include "collector.h"


int main(int argc, char *argv[]){
    int maxHeapSize;
    if(argc < 2){
        perror("Did not specify size of heap");
        exit(EXIT_FAILURE);
    }

    maxHeapSize = atoi(argv[1]);
    printf("[ Got heap size %d ]\n", maxHeapSize);
    if(maxHeapSize <= 1023 || maxHeapSize > 8192 || ((maxHeapSize&(maxHeapSize - 1)) != 0)){
        perror("Wrong size of heap");
        exit(EXIT_FAILURE);
    }
    
    Collector collector;

    Collector *myCollector = &collector;
    initialize(maxHeapSize, myCollector);

    heap_allocate(128, myCollector);
    heap_allocate(256, myCollector);
    heap_clear(myCollector);
}