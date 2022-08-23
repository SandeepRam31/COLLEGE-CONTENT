#include <stdio.h>
#include "polynomial.h"

int main(void) {
  poly* p1 = NULL;
  poly* p2 = NULL;
  poly* p3 = NULL;
  
  display(p1);
  add_term(p1, 10, 3);
  add_term(p1, 5, 2);
  display(p1);
  return 0;
}