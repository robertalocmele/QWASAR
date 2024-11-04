#include <stdio.h>
#include <string.h>

  char* reverse_string(char* param_1)
{
    int length = strlen(param_1); 
    int start = 0;                 
    int end = length - 1;          

    while (start < end) { 
        char temp = param_1[start];   
        param_1[start] = param_1[end];  
        param_1[end] = temp;          
        start++;
        end--;
    }
    return param_1;
}


int main() {
  char  my_str[] = "Hello";
  
  printf("Before reverse -> %s \n", my_str);
  printf("Reverse -> %s", reverse_string(my_str));
  return 0;
}
