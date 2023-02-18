#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if (space_char(c) == 0)
    return 1;
  return 0;
}

char *word_start(char *str)
{
  while(*str != '\0')
  {
    if (non_space_char(*str) == 1)
      return str;
  }

  return NULL;
}

char *word_terminator(char *word)
{
  char *temp = word_start(word);
  if (temp == NULL)
  {
    return NULL;
  }else
  {
    while(*temp != '\0')
      temp++;
  }
  return temp;
}


int count_words(char *str)
{


}


char *copy_str(char *intr, short len)
{


}


char **tokenize(char *str)
{


}


void print_tokens(char **tokens)
{


}


void free_tokens(char **tokens)
{


}
