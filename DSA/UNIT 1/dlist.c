#include <stdio.h>
#include "dlist.h"

int main(){
    list pl;
    initList(&pl);
    display(&pl);
    insertFront(&pl, 100);
    insertFront(&pl, 200);
    display(&pl);
    insertPos(&pl, 1, 50);
    insertPos(&pl, 2, 60);
    display(&pl);
    deletePos(&pl, 1);
    insertLast(&pl, 9);
    display(&pl);
    return 0;
}