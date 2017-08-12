#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "item.h"

static node *head;
static node *last;
static int size;

void Queue(void) {
  last = head = NULL;
  size = 0;
}

node *create(Item item, node *next) {
  node *entry = malloc(sizeof(*entry));

  if (!entry) {
    printf("Error: failed to create new node.\n");
    exit(EXIT_FAILURE);
  }

  entry->data = item;
  entry->next = next;

  size++;

  return entry;
}

void enqueue(Item item) {
  node *entry = create(item, NULL);

  if (!head) {
    head = last = entry;
  } else {
    last->next = entry;
    last = entry;
  }
}

Item dequeue(void) {
  if (!head) {
    exit(EXIT_FAILURE);
  }

  Item item = head->data;
  node *t = head->next;

  free(head);
  
  head = t;

  if (!t) {
    last = NULL;
  }

  --size;
  
  return item;
}

int queueSize(void) {
  return size;
}

int isQueueEmpty(void) {
  return !size;
}