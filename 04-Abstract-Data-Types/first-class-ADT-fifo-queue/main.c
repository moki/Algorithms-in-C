#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

int main(int argc, char **argv) {
  int i, j, n = atoi(*++argv), m = atoi(*++argv);

  qp queues[m];
  
  srand(time(NULL));

  for (i = 0; i < m; i++) {
    queues[i] = QueueInitialize();
  }

  for (j = 0; j < n; j++) {
    enqueue(queues[rand() % m], j);
  }
  
  for (i = 0; i < m; i++, printf("\n")) {
    for (j = 0; !isQueueEmpty(queues[i]); j++) {
      printf("%3d ", dequeue(queues[i]));
    }
  }

  return 0;
}