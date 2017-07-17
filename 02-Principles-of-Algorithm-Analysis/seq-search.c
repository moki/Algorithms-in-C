#include <stdio.h>
#include <stdlib.h>

static int *collection, *target, *size;
static void initialization(int);
static void representation(void);

int *seqsearch(int);

int main(int argc, char* *argv) {
  size = malloc(sizeof(int));
  *size = atoi(*++argv);

  collection = malloc(*size * sizeof(int));
  target = malloc(sizeof(int));

  initialization(*size);

  printf(
    "Input number 0 to %d, "
    "you want to find in the collection:\n",
    *size
  );

  while (scanf("%d", target) == 1) {
    printf("Entered number located at index: %d\n", (seqsearch(*target) - collection));
  }
}

static void initialization(int s) {
  int *cp = collection;
  int i = 0;
  while (i < s) {
    *cp++ = ++i;
  }
}

static void representation(void) {
  int *cp = collection;
  while (*(cp + 1)) {
    printf("%d\n", *cp++);
  }
}

int * seqsearch(int v) {
  int *cp = collection;
  while (*cp) {
    if (*cp == v) return cp;
    *cp++;
  }
}

