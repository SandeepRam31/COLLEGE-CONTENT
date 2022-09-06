#include <stdio.h>
#include "ployheader.h"

int main(){
    LLIST poly, poly2, polySum;

    initList(&poly);
    initList(&poly2);
    initList(&polySum);

    addTerm(&poly, 3, 2, 4);
    addTerm(&poly, 2, 3, 3);

    display(&poly);
    printf("\n");

    addTerm(&poly2, 5, 2, 4);
    addTerm(&poly2, 4, 1, 2);

    display(&poly2);
    printf("\n");

    add(&poly, &poly2, &polySum);
    display(&polySum);
}