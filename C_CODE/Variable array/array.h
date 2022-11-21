#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 32

typedef struct {

    int *array;
    int size;

} Array; //为什么不是指针 *Array 

Array array_create(int init_size);
void array_free(Array *array);
void array_inflate(Array *array, int more_size);
int array_size(const Array *array);
int *array_at(Array *array, int index);

#endif