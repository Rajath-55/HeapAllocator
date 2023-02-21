#ifndef COLLECTOR_H
#define COLLECTOR_H

// the collector struct 
typedef struct BumpCollector{
    int heapSize;
    char *heap;
    int bumpPointer;
    

}Collector;

extern void heap_allocate(int size, Collector *collector);
extern void heap_clear(Collector *collector);
extern void initialize(int totalSize, Collector *collector);
extern void destroy(Collector *collector);

#endif