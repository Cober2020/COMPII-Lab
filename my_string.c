#include "my_string.h"

struct vector{
  int size;
  int capacity;
  char* data;
};

typedef struct vector Vector;

MY_STRING my_string_init_default(void)
{
  Vector* pVector = malloc(sizeof(Vector*));

  if(pVector!= NULL)
    {
      pVector->size = 0;
      pVector->capacity = 1;
      pVector->data = malloc(sizeof(char)*pVector->capacity);
    }

  return (MY_STRING) pVector;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  int lengthOfString = 0;

  Vector* pVector = malloc(sizeof(Vector*));

  if(pVector != NULL)
    {
      while(c_string[lengthOfString] != '\0')
	lengthOfString++;
      pVector->size = lengthOfString;
      pVector->capacity = lengthOfString+1;
      pVector->data = malloc(sizeof(char)*pVector->capacity);
      for(int i = 0;i<lengthOfString;i++)
	{
	  pVector->data[i] = c_string[i];
	}
    }
  return (MY_STRING)pVector;
}


void my_string_destroy(MY_STRING* phMy_string)
{
  Vector* pVector = (Vector*) *phMy_string;

  free(pVector->data);
  free(pVector);

  *phMy_string = NULL;
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
  Vector* pLeft_vector = (Vector*)hLeft_string;
  Vector* pRight_vector = (Vector*)hRight_string;

  int i = 0;

  while(pLeft_vector->data[i] != '\0' && pRight_vector->data[i] != '\0')
    {
      if(pLeft_vector->data[i] > pRight_vector->data[i])
	{
	  return 2;
	}else if(pLeft_vector->data[i] < pRight_vector->data[i])
	{
	  return -2;
	}else if(pLeft_vector->data[i] == pRight_vector->data[i])
	{
	  i++;
	}
    }
  if(pLeft_vector->data[i] == '\0')
    return -2;
  return 2;


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
  Vector* pVector = (Vector*)hMy_string;

  if(pVector->size == pVector->capacity)
    {
      Vector* pTemp = (Vector*)malloc(sizeof(Vector));
      if(pTemp != NULL)
	{
	  pTemp->size = pVector->size;
	  pTemp->capacity = pVector->capacity*2;
	  pTemp->data = malloc(sizeof(char)*pTemp->capacity);

	  for(int i = 0;i<pVector->size;i++)
	    pTemp->data[i] = pVector->data[i];

	  pTemp->data[pTemp->size] = item;


	  pVector->size = pTemp->size+1;
	  pVector->capacity = pTemp->capacity;
	  pVector->data = pTemp->data;

	  my_string_destroy((MY_STRING)&pTemp);

	  return SUCCESS;
	}else{
	return FAILURE;
      }
    }else
    {
      pVector->data[pVector->size] = item;
      pVector->size++;
      return SUCCESS;
    }
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  Vector* pVector = (Vector*)hMy_string;

  if(pVector->size == 0)
    return FAILURE;

  pVector->size = pVector->size-1;

  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  Vector* pVector = (Vector*)hMy_string;

  if(pVector->size-1 < index)
    return FAILURE;

  return &pVector->data[index];
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  Vector* pResult = (Vector*)hResult;
  Vector* pAppend = (Vector*)hAppend;

  int i = 0;

  if(pResult->size + pAppend->size <= pResult->capacity)
    {
      while(pAppend->data[i] != '\0')
	{
	  pResult->data[++pResult->size] = pAppend->data[i];
	  pResult->size += 1;
	  i++;
	}
      return SUCCESS;
    }else
    {
      Vector* pTemp = (Vector*)malloc(sizeof(Vector));
      if(pTemp != NULL)
	{
	  pTemp->size = pResult->size;
	  pTemp->capacity = pResult->size + pAppend->size + 1;
	  pTemp->data = malloc(sizeof(char)*pTemp->capacity);

	  for(int i = 0;i<pResult->size;i++)
	    pTemp->data[i] = pResult->data[i];

	  while(pAppend->data[i] != '\0')
	    {
	      pTemp->data[pTemp->size] = pAppend->data[i];
	      pTemp->size += 1;
	      i++;
	    }

	  pResult->size = pTemp->size+1;
	  pResult->capacity = pTemp->capacity;
	  pResult->data = pTemp->data;

	  my_string_destroy((MY_STRING)&pTemp);

	  return SUCCESS;
	}else{
	return FAILURE;
      }

    }
}

void my_string_print(MY_STRING hMy_string)
{
  printf("The Size of the String is: %d.\nThe Capacity of the String is: %d.\n\nString: %s\n\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string), my_string_at(hMy_string, 0));

}

Boolean my_string_empty(MY_STRING hMy_string)
{
  Vector* pVector = (Vector*)hMy_string;

  if(pVector->size == 0)
    return TRUE;
  else
    return FALSE;
}
