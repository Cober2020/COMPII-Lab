//
//  main.c
//  Labs
//
//  Created by Chris Ober on 6/21/17.
//  Copyright © 2017 Chris Ober. All rights reserved.
//

#include "my_string.h"

int main(int argc, const char * argv[])
{
    MY_STRING hMy_string1 = NULL;
    
    MY_STRING hMy_string2 = NULL;
    
    hMy_string1 = my_string_init_c_string("Z");
    
    hMy_string2 = my_string_init_c_string("H");
    
    my_string_print(hMy_string1);
    printf("\n");
    
    my_string_push_back(hMy_string1, 'o');
    my_string_push_back(hMy_string1, 'e');
    
    my_string_print(hMy_string1);
    printf("\n");
    
    my_string_push_back(hMy_string2, 'i');
    my_string_push_back(hMy_string2, 'l');
    my_string_push_back(hMy_string2, 'l');
    my_string_push_back(hMy_string2, 'y');
    
    my_string_concat(hMy_string1, hMy_string2);
    
    my_string_print(hMy_string1);
    printf("\n");
    my_string_print(hMy_string2);
    printf("\n");
    
    MY_STRING hMy_string3 = NULL;
    
    hMy_string3 = my_string_init_default();
    
    int res;
    
    res = my_string_empty(hMy_string3);
    if(res == 1)
        printf("String is empty\n");
    else if(res == 0)
        printf("String is full\n");
    
    my_string_destroy(&hMy_string1);
    my_string_destroy(&hMy_string2);
    my_string_destroy(&hMy_string3);
    
    return 0;
}