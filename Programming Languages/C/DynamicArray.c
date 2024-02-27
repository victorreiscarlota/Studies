// Implementation of a dynamic array in C, based on an idea by tsoding.

// Feel free to test it, be creative with it. 





#include <stdio.h>
#include <stdlib.h>

#include "./config.h"

typedef struct {
    float *items;
    size_t count;
    size_t capacity;
} Numbers;

typedef struct {
    const char *items;
    size_t count;
    size_t capacity;
} Names; // you can be creative with the structs. 

typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} Prices;

int main(void) {
    Numbers xs = {0};

    for (int x = 0; x < ARRAY_SIZE; x++)
        DA_APPEND(xs, x);

    for (size_t i = 0; i < xs.count; i++)
        printf("%.2f\n", xs.items[i]);

    free(xs.items); 

    return 0;
}
