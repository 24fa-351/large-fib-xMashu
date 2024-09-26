#include <stdio.h>

long int iterative(long int n)
{
   if (n == 0)
   {
      return 0;
   }
   else if(n == 1)
   {
      return 1;
   }

long int current = 1;
long int prev = 0;
long int next = 0;
   for(int i = 1; i < n; ++i)
   {
      next = prev + current;
      prev = current;
      current = next;
   }
   return current;

}

long int recursion(long int n)
{
   if(n == 0)
   {
      return 0;
   }
   else if (n == 1)
   {
      return 1;
   }
   else
   {
      return recursion(n-1) + recursion(n-2);
   }
}



int main(int argc, char *argv[]) {

   int  commandLineInt = 0;

   sscanf(argv[1], "%d", &commandLineInt); //scan for first input and add to commandLineInt

   char fibOption = *argv[2]; // if recursive or iterative

long int n = 0;
   n = commandLineInt -1; 
   // -1 cuz fib has to start at 0

long int result = 0; //set to 0 so if no response it'll just default to 0

   if(fibOption == 'i')
   {
      result = iterative(n);
   }
   else if(fibOption == 'r')
   {
      result = recursion(n);
   }

   printf("%ld\n", result);

}