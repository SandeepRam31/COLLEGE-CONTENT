#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int coeff;
  int power;
  struct node* next;
} node;

typedef struct poly {
  node *head;
} poly;

node *createNode(int, int); // create 1 term of the polynomial like 10x^3
void add_term(
    poly *,
    int,
    int); // add the created term to the polynomial like 10x^3 + 4x^2 + 5
void display(poly *);
void addition(poly *, poly *,
              poly *); // add 2 polynomials and store it in a thrid

node *createNode(int c, int p) {
  node *Node = (node *)malloc(sizeof(node));
  Node->coeff = c;
  Node->power = p;
  return Node;
}

void display(poly *pl) {
  if (pl != NULL) {
    node *temp = pl->head;
    for (int i = 0; temp != NULL; i++) {
      printf("+(%dx^%d)", temp->coeff, temp->power);
      temp = temp->next;
    }
  } else {
    printf("POLYNOMIAL EMPTY");
  }
}
void add_term(poly *pl, int coeff, int power) {
  node *Node = createNode(coeff, power);
  if (pl == NULL)
    pl->head = Node;
  else {
    int found = 0;
    if (pl->head->power < power) {
      Node->next = pl->head;
      pl->head = Node;
      return;
    }

    node *temp = pl->head;

    while (!found) {
      if (temp->next->power < power) {
        Node->next = temp->next;
        temp->next = Node;
        return;
      }

      if (temp->next == NULL) {
        temp->next = Node;
        return;
      }
    }
  }
}