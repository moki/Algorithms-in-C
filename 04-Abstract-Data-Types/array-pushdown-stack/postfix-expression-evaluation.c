#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(int argc, char **argv) {
  char *s = *++argv;
  int length = strlen(s);
  int i;
  Stack();

  for (i = 0; i < length; i++) {
    if (*(s + i) == '+') {
      stackPush(stackPop() + stackPop());
    }
    
    if (*(s + i) == '*') {
      stackPush(stackPop() * stackPop());
    }

    if (*(s + i) >= '0' && *(s + i) <= '9') {
      stackPush(0);
    }

    while (*(s + i) >= '0' && *(s + i) <= '9') {
      stackPush(10 * stackPop() + (*(s + i++) - '0'));
    }
  }

  printf("%d\n", stackPop());
}
