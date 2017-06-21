#include "my_string.h"

int main(int argc, const char * argv[])
{
    MY_STRING hMy_string1 = NULL;
    
    MY_STRING hMy_string2 = NULL;
    
    int res;
    
    hMy_string1 = my_string_init_c_string("Z");
    
    hMy_string2 = my_string_init_c_string("H");
    
    res = my_string_compare(hMy_string1, hMy_string2);
    
    if(res == 2)
        printf("Left string is bigger!\n");
    else if(res == -2)
        printf("Right string is bigger!\n");
    else if(res == 0)
        printf("The two strings are the same!\n");

    my_string_destroy(&hMy_string1);
    my_string_destroy(&hMy_string2);
    
    return 0;
}
