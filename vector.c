#include "vector.h"

void vector_traverse(Vector* pVector)
{
    for(int i = 0; i < pVector->size; i++)
        printf("%c ", pVector->data[i]);
}

Vector* vector_init_default(void)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = malloc(sizeof(char)*pVector->capacity);
        if(pVector->data == NULL)
            return NULL;
        return pVector;
    }
    return NULL;
}

Status vector_insertion(Vector* pVector, int index, char data)
{
    if(pVector->size != pVector->capacity)
    {
        int i = pVector->size;
        pVector->size+=1;
        
        while(i >= index){
            pVector->data[i+1] = pVector->data[i];
            i -= 1;
        }
        
        pVector->data[index] = data;
        
        return SUCCESS;
    }
    return FAILURE;
}

Status vector_deletion(Vector* pVector, int index)
{
    if(pVector->size != 0)
    {
        int i = pVector->size;
        while(i <= index)
        {
            pVector->data[i-1] = pVector->data[i];
            i += 1;
        }
        
        pVector->size -= 1;
        return SUCCESS;
    }
    return FAILURE;
}

int vector_value_search(Vector* pVector, char value)
{
    int i = 0;
    while(i < pVector->size)
    {
        if(pVector->data[i]==value)
            return i;
        i += 1;
    }
    return -1;
}

char vector_index_search(Vector* pVector, int index)
{
    if(pVector->size < index)
        return -1;
    
    return pVector->data[index];
}

Status vector_update(Vector* pVector, int index, int item)
{
    if(pVector->size<index)
        return FAILURE;
    pVector->data[index-1] = item;
    return SUCCESS;
}
