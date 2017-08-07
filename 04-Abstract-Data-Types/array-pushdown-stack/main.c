#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv) {
  Stack();
  stackPush(4);
  stackPush(3);
  stackPush(2);
  stackPush(1);
  printf("%d\n", size);
  printf("%d\n", stackPop());
  printf("%d\n", stackPop());
  printf("%d\n", stackPop());
  printf("%d\n", stackPop());
}