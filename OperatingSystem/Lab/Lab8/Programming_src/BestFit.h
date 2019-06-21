#ifndef BEST_FIT_H
#define BEST_FIT_H
#include <stddef.h>

//Node:
struct mem_region;

//Define free_regions and used_regions:
struct mem_region *free_regions;
struct mem_region *used_regions;

//Initiate memory:
//return 0 if success, and 1 if failed:
int mem_init(size_t size);

//Allocate a list of size bytes memory in the preallocated regions created by mem_init():
void *mem_alloc(size_t size);

//Find the min region for best-fit:
struct mem_region *min_free_regions(size_t size);

//Print free_regions:
void print_free_regions(void);

//Print used_regions:
void print_used_regions(void);

//Free allocated memory:
void mem_free(void *ptr);

//Free used data:
void mem_finish();


#endif