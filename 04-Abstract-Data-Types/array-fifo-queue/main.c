#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv) {
  printf("Hello\n");
  Queue();
  printf("queue size: %d\n", queueSize());
  printf("enqueuing Item 1\n");
  enqueue(1);
  printf("queue size: %d\n", queueSize());
  printf("dequeued Item is: %d\n", dequeue());
  printf("enqueuing Item 2\n");
  enqueue(2);
  printf("dequeued Item is: %d\n", dequeue());
  printf("enqueuing Item 3\n");
  enqueue(3);
  printf("dequeued Item is: %d\n", dequeue());
  printf("queue size %d\n", queueSize());
  printf("enqueuing Item 1\n");
  enqueue(1);
  printf("enqueuing Item 2\n");
  enqueue(2);
  printf("enqueuing Item 3\n");
  enqueue(3);
  printf("queue size %d\n", queueSize());
  printf("dequeued Item is: %d\n", dequeue());
  printf("queue size %d\n", queueSize());
  printf("Bye\n");
}