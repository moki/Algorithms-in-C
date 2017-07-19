#include <stdio.h>
#include "point.h"

int main(int argc, char **argv) {
  point a, b;

  a.x = 1;
  a.y = 1;

  b.x = 2;
  b.y = 2;

  printf("distance between a and b is: %f\n", distance(a, b));

  return 0;
}