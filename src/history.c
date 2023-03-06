#include <stdlib.h>
#include <stdio.h>
#include "history.h"



List* init_history()
{
  List* history = (List*)malloc(sizeof(List));
  Item* newRoot = (Item*)malloc(sizeof(Item));
  history->root = newRoot;
  history->root->id = 0;
  // Small test printf("working\n");
  return history;
}

void add_history(List *list, char *str)
{
  Item *new = (Item*)malloc(sizeof(Item));
  new->str = str;
  if (list->root->id == 0)
  {
    list->root->str = str;
    list->root->id = 1;
    return;
  }

  while (list->root->next)
  {
    list->root = list->root->next;
  }
  list->root->next = new;
  new->id = list->root->id + 1;
  return;
}

char *get_history(List *list, int id)
{


}

void print_history(List *list)
{


}

void free_history(List *list)
{


}
