#include "item.h"

extern Item* stack;
extern int size;

void Stack(void);
Item stackPop(void);
void stackPush(Item);
int isStackEmpty(void);