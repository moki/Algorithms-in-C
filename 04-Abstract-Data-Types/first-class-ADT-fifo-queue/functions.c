#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "queue.h"

typedef struct node *n;

struct node {
  Item item;
  n next;
};

struct queue {
  n head;
  n last;
};

n create(Item i, n next) {
  n node = malloc(sizeof(*node));

  node->item = i;
  node->next = next;
 
  return node;
}

qp QueueInitialize(void) {
  qp queue = malloc(sizeof(*queue));
  queue->head = NULL;
  return queue;
}

void enqueue(qp q, Item i) {
  if (!q->head) {
    q->last = create(i, q->head);
    q->head = q->last;
    return ;
  }

  q->last->next = create(i, q->last->next);
  q->last = q->last->next;
}

Item dequeue(qp q) {
  Item i = q->head->item;
  n t = q->head->next;


  free(q->head);
  q->head = t;

  return i;
}

int isQueueEmpty(qp q) {
  return !q->head;
}