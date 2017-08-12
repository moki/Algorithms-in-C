#include "item.h"

typedef struct node {
  int data;
  struct node* next;
} node;

void Queue(void);

void enqueue(Item);
Item dequeue(void);

int queueSize(void);
int isQueueEmpty(void);

node *create(Item, node *);
