//
//  MY_STRING.h
//  Labs
//
//  Created by Chris Ober on 6/21/17.
//  Copyright © 2017 Chris Ober. All rights reserved.
//

#ifndef MY_STRING_h
#define MY_STRING_h

#include "vector.h"

typedef void* MY_STRING;

MY_STRING my_string_init_default(void);

void my_string_destroy(MY_STRING* phMy_string);

MY_STRING my_string_init_c_string(const char* c_string);

int my_string_get_capacity(MY_STRING hMy_string);

int my_string_get_size(MY_STRING hMy_string);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

#endif /* MY_STRING_h */
