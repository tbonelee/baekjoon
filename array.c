#include "stdio.h"
int main()
{
   int array[5];

   /* If %p is new to you, you can use %d as well */
   printf("array=%p : &array=%p\n", array, &array);

   return 0;
}