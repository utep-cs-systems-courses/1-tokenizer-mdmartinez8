#include <stdio.h>
#include <stdlib.h>
//#include "tokenizer.h"
//#include "history.h"
#define maxLength 1000

int main()
{
  int isRunning = 1;
  char *input = (char *)malloc(maxLength*sizeof(char));
  while(isRunning)
  {
    fputs("Enter string to save.\tEnter !1 to view history.\n", stdout);
    fputs(">", stdout);
    gets(input);
    if (*input == 'q')
    {
      isRunning = 0;
      break;
    }
    printf("%d", space_char(*input));
    
    //printf("%s\n\n", input);


  }

  return 0;
}
