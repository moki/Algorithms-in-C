#include <stdio.h>
#include "stack.h"
#include "node.h"

int main(int argc, char **argv) {
  printf("Hello\n");
  Stack();
  printf("stack size: %d\n", size);
  stackPush(1);
  printf("head element data is: %d\n", stackPop());
  stackPush(2);
  printf("head element data is: %d\n", stackPop());
  stackPush(3);
  printf("head element data is: %d\n", stackPop());
  printf("stack size: %d\n", size);
  stackPush(1);
  stackPush(2);
  stackPush(3);
  stackPush(3); // duplicate entry pushes ignored
  stackPush(2); // duplicate entry pushes ignored
  printf("stack size: %d\n", size);
  printf("head element data is: %d\n", stackPop());
  printf("head element data is: %d\n", stackPop());
  printf("head element data is: %d\n", stackPop());
  printf("Bye\n");
}