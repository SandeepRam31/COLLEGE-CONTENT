#include<stdio.h>
#include<stdlib.h>
#include "singlylinked.h"

/*
LAB 1: Add 2 polynomials stores as a singly linked list
struct poly{
    int coeff,
    int px,
    int py;
    struct poly *next;
};

Delete alternate nodes in a singly linked list
*/


int main(){
    LLIST pl;
    initList(&pl);
    insertFront(&pl, 60);
    insertFront(&pl, 50);
    insertFront(&pl, 40);
    insertFront(&pl, 30);
    insertFront(&pl, 20);
    insertFront(&pl, 10);
    deleteAlternate(&pl);
    return 0;
}