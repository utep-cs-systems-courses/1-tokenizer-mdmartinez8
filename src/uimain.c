#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define maxLength 1000

int main()
{
  int isRunning = 1;
  char *input = (char *)malloc(maxLength*sizeof(char));
  List* history = init_history();
  //fputs("%d", history->root->id);
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
    
    char **tokens = tokenize(input);
    print_tokens(tokens);
    //Test  printf("%s\n", word_start(input));
    //Test  printf("%s\n", word_terminator(input));
    //Test  printf("%d\n", count_words(input));
    
    printf("%s\n\n", input);


  }

  return 0;
}
