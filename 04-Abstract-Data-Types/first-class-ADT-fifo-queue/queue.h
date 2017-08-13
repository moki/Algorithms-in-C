#include "item.h"

typedef struct queue *qp;

qp QueueInitialize(void);

void enqueue(qp, Item);
Item dequeue(qp);

int isQueueEmpty(qp);

void QueueFinalize(qp);