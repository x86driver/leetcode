#pragma once
#include <stdbool.h>

struct ListItem {
  const void *data;
  struct ListItem *next;
};

typedef struct List {
  int size;
  struct ListItem *head;
  struct ListItem *tail;
} List;

List *create_list();
bool insert_to_list(List *list, const void *data);
void destroy_list(List *list);
