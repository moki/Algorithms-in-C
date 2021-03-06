#include <stdio.h>
#include <stdlib.h>

static int *cmps, *cmpszs, *count, threshold;

static void initialization(int sites);
static void representation(void);
static int belongs(int);

int getCount(void);
int findRoot(int);
int connected(int, int);
int connect(int, int);

int main(int argc, char *argv[]) {
  count = malloc(sizeof(int));
  *count = atoi(*++argv);

  threshold = *count;

  cmps = malloc(*count * sizeof(int));
  cmpszs = malloc(*count * sizeof(int));

  initialization(*count);
  representation();

  int p, q, lps;
  printf("Input pair p and q you want to connect, separated by space.\n");
  
  do {
    lps = scanf("%d %d\n", &p, &q);
    if (lps == 2 && connect(p, q)) {
      printf("Connected %d and %d\n", p, q);
    } else {
      continue;
    }
  } while (lps == 2);
  
  representation();

  return 0;
}

static int isvalid(int p) {
  return p >= 0 && p < threshold;
}

static void initialization(int sites) {
  int *cmpsp = cmps;
  int *cmpszsp = cmpszs;
  int i = 0;
  while (i < sites) {
    *cmpsp++ = i++;
    *cmpszsp++ = 1;
  }
}

static void representation(void) {
  int *dsp = cmps;
  printf("Site-components pairs: ");
  while (*(dsp + 1)) {
    printf("%d ", *dsp++);
  }
  printf("\n");
}

int getCount(void) {
  return *count;
}

int findRoot(int site) {
  if (!isvalid(site)) {
    printf("Program was provided with errornous values, shutting down.\n");
    exit(EXIT_FAILURE);
  }

  int next;

  for (next = site; next != *(cmps + next); next = *(cmps + next));

  *(cmps + next) = *(cmps + *(cmps + next));

  return next;
}

int connected(int p, int q) {
  if (!isvalid(p) || !isvalid(q)) {
    printf("Program was provided with errornous values, shutting down.\n");
    exit(EXIT_FAILURE);
  }
  
  return findRoot(p) == findRoot(q);
}

int connect(int p, int q) {
  if (!isvalid(p) || !isvalid(q)) {
    printf("Program was provided with errornous values, shutting down.\n");
    exit(EXIT_FAILURE);
  }

  if (connected(p, q)) {
    return 0;
  }

  int p = findRoot(p);
  int q = findRoot(q);

  if (*(cmpszs + p) < *(cmpszs + q)) {
    *(cmps + p) = q;
    *(cmpszs + q) += *(cmpszs + p);
  } else {
    *(cmps + q) = p;
    *(cmpszs + p) += *(cmpszs + q);
  }

  --*count;

  return 1;
}