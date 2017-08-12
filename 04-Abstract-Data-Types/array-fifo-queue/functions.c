#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "item.h"

static Item *queue;
static int head, last, size;

void Queue(void) {
  queue = malloc(sizeof(*queue));
  head = last = size = 0;
}

void enqueue(Item item) {
  queue = realloc(queue, ++size * sizeof(*queue));

  if (!queue) {
    printf("Failed to allocate space for a new item in queue");
    exit(EXIT_FAILURE);
  }

  *(queue + ++last) = item;
}

Item dequeue(void) {
  --size;
  return *(queue + ++head);
}

int queueSize(void) {
  return size;
}

int isQueueFull(void) {
  return last == size;
}

int isQueueEmpty(void) {
  return head == last;
}