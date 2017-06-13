#include "my_string.h"

int main(int argc,char* argv[])
{
  MY_STRING hMy_string1 = NULL;

  MY_STRING hMy_string2 = NULL;

  hMy_string1 = my_string_init_c_string("My Name is ");

  my_string_print(hMy_string1);

  my_string_destroy(&hMy_string1);

  my_string_destroy(&hMy_string2);

  return 0;
}
