#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(int argc, char **argv) {
  char *s = *++argv;

  int i, n = strlen(s);

  for (i = 0; i < n; i++) {
    if (*(s + i) == ')') {
      printf("%c ", stackPop());
    }

    if (*(s + i) == '+' || *(s + i) == '*') {
      stackPush(*(s + i));
    }

    if (*(s + i) >= '0' && *(s + i) <= '9') {
      printf("%c", *(s + i));
    }
  }

  putchar('\n');
}