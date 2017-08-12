#include "item.h"

typedef struct node {
  Item data;
  struct node *next;
} node;

extern node *head;
extern Item *occurs;