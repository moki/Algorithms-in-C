#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stack.h"

node *head = NULL;
Item *occurs = NULL;
int size = 0;

void Stack(void) {
  head = malloc(sizeof(*head));
  occurs = malloc(sizeof(*occurs));
}

void stackPush(Item item) {
  node *element = malloc(sizeof(*element));

  if (!element) {
    printf("Error: failed to create new node.\n");
    exit(EXIT_FAILURE);
  }

  occurs = realloc(occurs, item * sizeof(*occurs));
  
  if (*(occurs + item)) {
    printf("Trying to push duplicate item, operation ignored.\n");
    return ;
  } else {
    *(occurs + item) = 1;
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

  *(occurs + top) = 0;

  return top;
}

int isStackEmpty(void) {
  return !size;
}