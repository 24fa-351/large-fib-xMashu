
#include <stdio.h>


long long int iterative(long long int n)
{
   if (n == 0)
   {
      return 0;
   }
   else if(n == 1)
   {
      return 1;
   }

   long long int current = 1;
   long long int prev = 0;
   long long int next = 0;
   for(int i = 1; i < n; ++i)
   {
      next = prev + current;
      prev = current;
      current = next;
   }
   return current;

}

long long int recursion(long long int n)
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

//https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Iterative-Fibonacci.html
// helped with understanding iterative fib again





int main(int argc, char *argv[]) {

   int  commandLineInt = 0;
   sscanf(argv[1], "%d", &commandLineInt);
   //https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion/

   char fibOption = *argv[2];
   char *filename = argv[3];


   //scanf("%s", filename);
   FILE *file = fopen(filename, "r"); 
   // https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm


   int fileInteger;
   fscanf(file, "%d", &fileInteger);
   //https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
   fclose(file);

   long long int n = 0;
   n = commandLineInt + fileInteger -1; 
   // -1 cuz fib has to start at 0




   long long int result = 0;
 
   if(fibOption == 'i')
   {
      result = iterative(n);
   }
   else if(fibOption == 'r')
   {
      result = recursion(n);
   }

   printf("%lld\n", result);





}