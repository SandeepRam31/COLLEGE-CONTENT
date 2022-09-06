#include <stdio.h>
#include "polynomial.h"

int main(void) {
  poly p1;
  poly p2;
  poly p3;

  initList(&p1);
  display(&p1);
  add_term(&p1, 10, 3);
  add_term(&p1, 5, 2);
  display(&p1);
  return 0;
}