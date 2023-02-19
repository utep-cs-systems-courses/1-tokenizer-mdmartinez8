#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)     //Returns 1 if whitespace
{
  if (c == ' ' || c == '\t' || c == '\n')
    return 1;
  return 0;
}

int non_space_char(char c)     //Returns 1 if not a whitespace
{
  if (space_char(c) == 0)
    return 1;
  return 0;
}

char *word_start(char *str)    //Returns pointer to first char in word, or NULL if no word exists
{
  while(*str != '\0')
  {
    if (non_space_char(*str) == 1)
      return str;
    str++;
  }

  return 0;
}

char *word_terminator(char *word)     //Returns pointer to last char in word
{
  while(*word != '\0' && non_space_char(*word) == 1)
  {
    word++;
  }
  word--;
  return word;
}


int count_words(char *str)
{
  int count = 0;

  while (*str != '\0')
  {
    if ((str = word_start(str)))
      count++;
    str = word_terminator(str);
    str++;
  }
  return count;
}


char *copy_str(char *intr, short len)
{
  char *strCopy = (char *)malloc((len)*sizeof(char));
  while (*intr != '\0' && non_space_char(*intr) == 1)
  {
    *strCopy++ = *intr++;
  }
  return strCopy;
}


char **tokenize(char *str)
{
  int count = count_words(str);
  char **tokens = (char **)malloc((count+1) * sizeof(char *));
  int i;
  for (i = 0; i < count; i++)
  {
    str = word_start(str);
    int wordLen = word_terminator(str) - str;
    tokens[i] = copy_str( str, (wordLen+1));
    str = word_terminator(str);
    str++;
  }
  i++;
  tokens[i] = 0;
  return tokens;
}


void print_tokens(char **tokens)
{
  while (*tokens != 0)
  {
    printf("%s\n", *tokens);
    *tokens++;
  }
}


void free_tokens(char **tokens)
{


}
