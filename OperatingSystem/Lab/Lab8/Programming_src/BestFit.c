#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "BestFit.h"

void *mem_pool = NULL;

//Mutex:
pthread_mutex_t lock;


//Node:
struct mem_region{
    size_t size; //size of memory region
    char *ptr; //ptr to the first byte
    struct mem_region *next; //ptr to the next region
    struct mem_region *prev; //ptr to the prev region
};

//static ptr to allocate memory:
static void *best_fit_allocator(size_t size);

//Implement mem_init():
int mem_init(size_t size){
    //Initiate lock for multi-threaded allocators:
    pthread_mutex_init(&lock, NULL);

    //Preallocate the mem pool:
    mem_pool = malloc(size);

    //Initiate free linked-list with only 1 region:

    //Malloc regions using malloc:
    free_regions = (struct mem_region* )malloc(sizeof(struct mem_region));

    //Allocate vals for free-regions:
    free_regions->size = size;
    free_regions->ptr = (char *)mem_pool;
    free_regions->next = NULL;
    free_regions->prev = NULL;

    return (mem_pool != 0);
}

//Implement mem_finish():
void mem_finish() {
	/* Delete lock */
	pthread_mutex_destroy(&lock);
	
	/* Clean lists */
	struct mem_region * tmp;
	if (free_regions != NULL) {
		tmp = free_regions->next;
		while (tmp != NULL) {
			free(free_regions);
			free_regions = tmp;
			tmp = tmp->next;
		}
		free(free_regions);
	}
	if (used_regions != NULL) {
		tmp = used_regions->next;
		while (tmp != NULL) {
			free(used_regions);
			used_regions = tmp;
			tmp = tmp->next;
		}
		free(used_regions);
	}
	
	/* Clean preallocated region */
	free(mem_pool);
}


//Implement mem_alloc():
void *mem_alloc(size_t size){
    pthread_mutex_lock(&lock);
    void *ptr = best_fit_allocator(size);

    // FOR VERIFICATION ONLY. DO NOT REMOVE THESE LINES
	if (ptr != NULL) {
		printf("Alloc [%4zu bytes] %p-%p\n", size, ptr, (char*)ptr + size - 1);
	}
    else {
		printf("Alloc [%4zu bytes] NULL\n", size);
	}

    pthread_mutex_unlock(&lock);
    return ptr;
}

//Implement mem_free():
void mem_free(void * ptr) {
	pthread_mutex_lock(&lock);
	struct mem_region * current_region = used_regions;
	// Get allocated region from the list of used_regions
	while (current_region != NULL && current_region->ptr != ptr) {
		current_region = current_region->next;
	}
	if (current_region != NULL) {
		// Remove current region from the list of used regions
		if (current_region == used_regions) {
			used_regions = used_regions->next;
			if (used_regions != NULL) {
				used_regions->prev = NULL;
			}
		}
		else {
			if (current_region->prev != NULL) {
				current_region->prev->next = current_region->next;
			}
			if (current_region->next != NULL) {
				current_region->next->prev = current_region->prev;
			}
		}

		// FOR VERIFICATION ONLY. DO NOT REMOVE THESE LINES
		printf("Free  [%4ld bytes] %p-%p\n", current_region->size, current_region->ptr,
				current_region->ptr + current_region->size - 1);

		// Free this region by putting it into free list
		if (free_regions == NULL) {
			// No free region
			free_regions = current_region;
		}
		else {
			// Find a location of the list for it
			if (current_region->ptr < free_regions->ptr) {
				// new region will be put on the first location
				if (current_region->ptr + current_region->size == free_regions->ptr) {
					// The new regions and the first region in the list are contiguous
					free_regions->ptr = current_region->ptr;
					free_regions->size += current_region->size;
					free(current_region);
				}
				else {
					// These regions are not contiguous
					free_regions->prev = current_region;
					current_region->prev = NULL;
					current_region->next = free_regions;
					free_regions = current_region;
				}
			}
			else {
				// new region will be put on somewhere in the middle or at the end of the list
				struct mem_region * tmp = free_regions;
				while (tmp->ptr < current_region->ptr && tmp->next != NULL) {
					tmp = tmp->next;
				}
				if (tmp->ptr < current_region->ptr) {
					// new region will be put at the end of the list
					if (tmp->ptr + tmp->size == current_region->ptr) {
						// Merge two contiguous regions
						tmp->size += current_region->size;
						free(current_region);
					}
					else {
						tmp->next = current_region;
						current_region->prev = tmp;
						current_region->next = NULL;
					}
				}
				else {
					// new region is in the middle of the list
					if (tmp->prev->ptr + tmp->prev->size == current_region->ptr) {
						// current_region and its previous one are contiguous
						tmp->prev->size += current_region->size;
						free(current_region);
						current_region = tmp->prev;
					} 
					else {
						current_region->prev = tmp->prev;
						current_region->next = tmp;
						tmp->prev->next = current_region;
						tmp->prev = current_region;
					}
					if (current_region->ptr + current_region->size == tmp->ptr) {
						// current region and its next one are contiguous
						current_region->size += tmp->size;
						current_region->next = tmp->next;
						if (tmp->next != NULL) {
							tmp->next->prev = current_region;
						}
						free(tmp);
					}
				}
			}
		}
	}
	pthread_mutex_unlock(&lock);
}

void *best_fit_allocator(size_t size){
    //TODO: Implement best-fit memory allocation:
    bool found = false;
    struct mem_region *current_region = min_free_regions(size);

    //Check if found:
    if (current_region != NULL){
        found = true;
    }

    //if found the used free_regions are considered as used_regions:
    if (found) {
		struct mem_region* tmp =
			(struct mem_region*)malloc(sizeof(struct mem_region));
		tmp->ptr = current_region->ptr;
		tmp->size = size;
		tmp->next = used_regions;
		tmp->prev = NULL;

		if (used_regions == NULL) {
			used_regions = tmp;
		}
		else {
			used_regions->prev = tmp;
			used_regions = tmp;
		}

		if (current_region->size == size) {
			if (current_region == free_regions) {
				free_regions = free_regions->next;
				if (free_regions != NULL) {
					free_regions->prev = NULL;
				}
			}
			else {
				if (current_region->prev != NULL) {
					current_region->prev->next = current_region->next;
				}
				if (current_region->next != NULL) {
					current_region->next->prev = current_region->prev;
				}
			}
			free(current_region);
		}
		else {
			current_region->ptr += size;
			current_region->size -= size;
		}
		return tmp->ptr;
	}
	else {
		return NULL;
	}
}

//Find the min mem_region in free_regions:
struct mem_region *min_free_regions(size_t size){
    struct mem_region *ptr = free_regions;
    size_t min_size = ptr->size;
    while(ptr->next != NULL){
        if (ptr->size >= size && ptr->size < min_size){
            min_size = ptr->size;
        }
        ptr = ptr->next;
    }

    return ptr;
}

//Print the free_regions:
void print_free_regions() {
    struct mem_region *ptr = free_regions;
    printf("free_regions = [");
    while (ptr->next != NULL){
        if (ptr->next == NULL){
            printf("%ld]\n", ptr->size);
        }

        printf("%ld, ", ptr->size);
        ptr = ptr->next;
    }
}

//Print the used_region:
void print_used_region() {
    struct mem_region *ptr = used_regions;
    printf("used_regions = [");
    while (ptr->next != NULL){
        if (ptr->next == NULL){
            printf("%ld]\n", ptr->size);
        }

        printf("%ld, ", ptr->size);
        ptr = ptr->next;
    }
}
