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
    Vector* pVector = (Vector*) hMy_string;
    
    return pVector->size;
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