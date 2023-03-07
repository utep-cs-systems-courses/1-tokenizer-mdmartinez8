#include <stdlib.h>
#include <stdio.h>
#include "history.h"



List* init_history()
{
  List* history = (List*)malloc(sizeof(List));
  Item* newRoot = (Item*)malloc(sizeof(Item));
  history->root = newRoot;
  history->root->id = 0;
  history->root->next = NULL;
  // Small test printf("working\n");
  return history;
}

void add_history(List *list, char *str)
{
  Item *new = (Item*)malloc(sizeof(Item));
  Item *temp = list->root;
  new->str = str;
  new->next = NULL;
  if (temp->id == 0)
  {
    temp->str = str;
    temp->id = 1;
    temp->next = NULL;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new;
  new->id = temp->id + 1;
  return;
}

char *get_history(List *list, int id)
{
  char *noId = "History not found.\n";
  Item *temp = list->root;
  while (temp != NULL)
    {
      if (temp->id == id)
	return temp->str;
      temp = temp->next;
    }
  return noId;
}

void print_history(List *list)
{
  Item *temp = list->root;
  while (temp != NULL)
    {
      printf("%d. %s\n", temp->id, temp->str);
      temp = temp->next;
    }
  return;
}

void free_history(List *list)
{


}
