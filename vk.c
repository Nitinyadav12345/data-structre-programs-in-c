#include <stdio.h>
int main() {
   static int a = 8;
   int b = 10;
   a = 9;
   printf("Value of static variable : %d\n", a);
   printf("Value of non-static variable : %d\n", b);
   return 0;
}
