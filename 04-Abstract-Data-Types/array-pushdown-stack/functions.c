#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "stack.h"

Item *stack = NULL;
int size = 0;

void Stack(void) {
  stack = malloc(sizeof(*stack));
}

void stackPush(Item item) {
  stack = realloc(stack, ++size * sizeof(*stack));

  if (!stack) {
    exit(EXIT_FAILURE);
  }

  *(stack + (size - 1)) = item;
}

Item stackPop() {
  if (isStackEmpty()) {
    exit(EXIT_FAILURE);
  }
  --size;
  return *(stack + size);
}

int isStackEmpty(void) {
  return !size;
}
