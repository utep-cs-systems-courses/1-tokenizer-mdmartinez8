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
  printf("%d\n", history->root->id); // To make sure first node is created properly
  while(isRunning)
  {
    fputs("Enter string to save.\tEnter !! to view history.\tEnter q to quit program.\n", stdout);
    fputs(">", stdout);
    gets(input);
    if (*input == 'q')
    {
      isRunning = 0;
      break;
    }

    if (*input == '!')
    {
      input++;
      if (*input != '!')
      {
	int id = *input - '0';
	printf("%s\n", get_history(history, id));
      }else
      {
	print_history(history);
      }
      input--;
    }
    char **tokens = tokenize(input);

    while (*tokens != 0)
    {
      add_history(history, *tokens);
      *tokens++;
    }
    //add_history(history, input);
    //Test  printf("%s\n", history->root->str);
    print_tokens(tokens);
    //Test  printf("%s\n", word_start(input));
    //Test  printf("%s\n", word_terminator(input));
    //Test  printf("%d\n", count_words(input));
    //free_tokens(tokens);
  }
  free_history(history);
  return 0;
}
