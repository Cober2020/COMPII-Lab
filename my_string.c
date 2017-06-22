//
//  MY_STRING.c
//  Labs
//
//  Created by Chris Ober on 6/21/17.
//  Copyright © 2017 Chris Ober. All rights reserved.
//

#include "my_string.h"

MY_STRING my_string_init_default(void)
{
    Vector* pVector = vector_init_default();
    
    return (MY_STRING)pVector;
}

void my_string_destroy(MY_STRING* phMy_string)
{
    Vector* pVector = (Vector*) *phMy_string;
    
    free(pVector->data);
    free(pVector);
    *phMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
    int i = 0,stringLength = 0;
    
    while(c_string[i] != '\0')
    {
        stringLength++;
        i++;
    }
    
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(pVector!=NULL)
    {
        pVector->size = stringLength;
        pVector->capacity = pVector->size + 1;
        pVector->data = malloc(sizeof(char)*pVector->capacity);
        if(pVector->data==NULL)
            return NULL;
        
        i = 0;
        
        while(c_string[i] != '\0')
        {
            pVector->data[i] = c_string[i];
            i++;
        }
        
        return (MY_STRING)pVector;
    }
    return NULL;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
    Vector* pVector = (Vector*) hMy_string;
    
    return pVector->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
    int i = 0, stringLength = 0;
    
    Vector* pVector = (Vector*) hMy_string;
    
    while(pVector->data[i] != '\0')
    {
        stringLength++;
        i++;
    }
    
    return stringLength;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
    Vector* pLeft_string = (Vector*) hLeft_string;
    Vector* pRight_string = (Vector*) hRight_string;
    
    int i = 0;
    
    if(pLeft_string->data[i] > pRight_string->data[i])
        return 2;
    else if(pLeft_string->data[i] < pRight_string->data[i])
        return -2;
    else if(pLeft_string->data[i] == pRight_string->data[i])
    {
        while(pLeft_string->data[i] != '\0' && pRight_string->data[i] != '\0')
        {
            i += 1;
            
            if(pLeft_string->data[i] > pRight_string->data[i])
                return 2;
            else if(pLeft_string->data[i] < pRight_string->data[i])
                return -2;
        }
        if(pLeft_string->data[i] == '\0' && pRight_string->data[i] == '\0')
            return 0;
        else if(pLeft_string->data[i] == '\0')
            return -2;
        else if(pRight_string->data[i] == '\0')
            return 2;
    }
    return -1;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    Vector* pVector = (Vector*)hMy_string;
    
    while(fscanf(fp, "%s", pVector->data) != EOF)
    {
        
        return SUCCESS;
    }
    return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
    Vector* pVector = (Vector*)hMy_string;
    
    fprintf(fp, "%s", pVector->data);
    
    return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
    Vector* pVector = (Vector*) hMy_string;
    
    if(pVector->size == pVector->capacity)
    {
        if(!vector_resize(pVector))
        {
            return FAILURE;
        }
    }
    
    pVector->data[pVector->size] = item;
    pVector->size += 1;
    
    return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
    Vector* pVector = (Vector*)hMy_string;
    
    if(pVector->size == 0)
        return FAILURE;
    
    pVector->size -= 1;
    
    return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
    Vector* pVector = (Vector*)hMy_string;
    
    if(pVector->size<index)
        return FAILURE;
    
    return &pVector->data[index];
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
    Vector* pResult = (Vector*)hResult;
    Vector* pAppend = (Vector*)hAppend;
    
    while(pResult->size + pAppend->size > pResult->capacity)
    {
        vector_resize(pResult);
    }
    
    int i = 0;
    int pSize = pResult->size;
    
    while(i < pAppend->size)
    {
        vector_insertion(pResult, pSize + i, pAppend->data[i]);
        i+=1;
    }
    
    return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
    Vector* pVector = (Vector*)hMy_string;
    
    if(pVector->size == 0)
        return TRUE;
    else
        return FALSE;
}

void my_string_print(MY_STRING hMy_string)
{
    Vector* pVector = (Vector*)hMy_string;
    
    vector_traverse(pVector);
    
    return;
}
