#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <stdlib.h>
#include "status.h"

struct vector{
    int size;
    int capacity;
    char* data;
};

typedef struct vector Vector;

void vector_traverse(Vector* pVector);

Status vector_insertion(Vector* pVector, int index, char data);

Vector* vector_init_default(void);

int vector_value_search(Vector* pVector, char value);

char vector_index_search(Vector* pVector, int index);

Status vector_update(Vector* pVector, int index, int item);

#endif /* vector_h */