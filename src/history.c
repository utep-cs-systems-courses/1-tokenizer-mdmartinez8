#include "history.h"



List* init_history()
{
  List* history;
  history->root->id = 0;
  return history;
}

void add_history(List *list, char *str)
{
  Item *temp = list->root;
  if (temp->id == 0)
  {
    temp->str = str;
    temp->id += 1;
    return;
  }

  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next->str = str;
  temp->next->id = temp->id + 1;
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
