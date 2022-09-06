#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int coeff;
    int px;
    int py;
    struct node* next;
} NODE;

typedef struct head{
    NODE* head;
} LLIST;

NODE* createNode(int, int, int); //done
void initList(LLIST*); //done
void addTerm(LLIST*, int, int, int); //done
void display(LLIST*); //done
void add(LLIST*,LLIST*,LLIST*);

void initList(LLIST* pl){
    pl->head = NULL;
    return;
}


NODE* createNode(int c, int px, int py){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->coeff = c;
    node->px = px;
    node->py = py;
    node->next = NULL;
    return node;
}

void addTerm(LLIST* pl, int c, int px, int py){
    NODE* node = createNode(c, px, py);

    if (pl->head == NULL){
        pl->head = node;
    } else {
        node->next = pl->head;
        pl->head = node;
    }
}


void display(LLIST* pl){
    NODE* temp = pl->head;
    if (pl->head == NULL) return;

    while(temp != NULL){
        printf("+(%dx^%dy^%d)", temp->coeff, temp->px, temp->py);
        temp = temp->next;
    }
}

void add(LLIST* p1, LLIST* p2, LLIST* p){
    NODE* temp_1 = p1->head;
    NODE* temp_2 = p2->head;
    NODE* node;

    int c, match = 0;

    if (p1->head == NULL) {
        p = p2;
    }
    else if (p2->head == NULL) {
        p = p1;
        }
    else {
        while (temp_1 != NULL){
            while (temp_2 != NULL){
                if ((temp_2->px == temp_1->px) && (temp_2->py == temp_1->py)){
                    match = 1;
                    c = temp_1->coeff + temp_2->coeff;
                    addTerm(p, c, temp_1->px, temp_1->py); 
                }
                
                temp_2 = temp_2->next;
            }
            temp_2 = p2->head;
            if (match != 1){
                addTerm(p, temp_1->coeff, temp_1->px, temp_1->py);
                match = 0;
            }
            temp_1 = temp_1->next;
        }

        match = 0;
        
        while (temp_2 != NULL){
            while (temp_1 != NULL){
                if ((temp_1->px == temp_2->px) && (temp_2->py == temp_1->py)){
                    match = 1;
                }
                
                temp_1 = temp_1->next;
            }
            temp_1 = p1->head;
            if (match != 1){
                addTerm(p, temp_2->coeff, temp_2->px, temp_2->py);
                match = 0;
            }
            temp_2 = temp_2->next;
        }
    }
}