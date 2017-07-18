#include <stdio.h>
#include <stdlib.h>

static int *collection, *target, *size;
static void initialization(int);
static void representation(void);

int *binarysearch(int);
int *binarysearchbase(int, int, int);

int main(int argc, char * *argv) {
  size = malloc(sizeof(int));
  *size = atoi(*++argv);

  collection = malloc(*size * sizeof(int));
  target = malloc(sizeof(int));

  initialization(*size);

  printf(
    "Input number 1 to %d, "
    "you want to find in the collection:\n",
    *size
  );

  while (scanf("%d", target) == 1) {
    printf("Entered number located at index: %d\n", (binarysearch(*target) - collection));
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

int *binarysearch(int v) {
  return binarysearchbase(v, 0, *size);
}

int *binarysearchbase(int v, int l, int r) {
  int *cp = collection;
  int m = (l + r) / 2;
  if (*(cp + m) == v) {
    return cp + m;
  } else if (*(cp + m) < v) {
    return binarysearchbase(v, m + 1, r);
  } else {
    return binarysearchbase(v, l, m - 1);
  }
}

