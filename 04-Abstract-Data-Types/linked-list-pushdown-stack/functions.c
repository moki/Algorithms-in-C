#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stack.h"

node *head = NULL;
int size = 0;

void Stack(void) {
  head = malloc(sizeof(*head));
}

void stackPush(Item item) {
  node *element = malloc(sizeof(*element));

  if (!element) {
    printf("Error: failed to create new node.\n");
    exit(EXIT_FAILURE);
  }

  element->data = item;
  element->next = head;

  head = element;
  size++;
}

Item stackPop(void) {
  if (!head || isStackEmpty()) {
    printf("Error: stack is empty.\n");
    exit(EXIT_FAILURE);
  }

  Item top = head->data;
  node *t = head->next;
  
  free(head);
  head = t;

  size--;
  return top;
}

int isStackEmpty(void) {
  return !size;
}