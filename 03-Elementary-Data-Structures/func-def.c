#include <stdio.h>

int lg(int);

int main() {
  int i, n;

  for (i = 1, n = 10; i <= 6; ++i, n*= 10) {
    printf("%7d %2d %9d\n", n, lg(n), n * lg(n));
  }
}

int lg(int n) {
  int i;

  for (i = 0; n > 0; ++i, n /= 2);

  return i;
}