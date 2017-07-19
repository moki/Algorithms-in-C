#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;

struct node {
  int item;
  link next;
};

int main(int argc, char **argv) {
  int i, n = atoi(*++argv), m = atoi(*++argv);

  link t = malloc(sizeof *t);
  link x = t;
  t -> item = 1;
  t -> next = t;

  for (i = 2; i <= m; ++i) {
    x = (x -> next = malloc(sizeof *x));
    x -> item = i;
    x -> next = t;
  }

  while (x != x -> next) {
    for (i = 1; i < m; ++i) {
      x = x -> next;
    }

    x -> next = x -> next -> next; n--;
  }

  printf("%d\n", x -> item);
}