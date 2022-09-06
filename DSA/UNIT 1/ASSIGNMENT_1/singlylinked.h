#include<stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
} NODE;

typedef struct hp{
    NODE* head;
} LLIST;

void initList(LLIST* pl){
    pl->head = NULL;
}

NODE* createNode(int data){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertFront(LLIST* pl, int data){
    if (pl->head ==NULL){
        NODE* node = createNode(data);
        pl->head = node;
    } else {
        NODE* node = createNode(data);
        node->next = pl->head;
        pl->head = node;
    }
}

void insertPos(LLIST* pl, int data, int index){
    NODE* node = createNode(data);
    int count = 0;
    NODE* temp = pl->head;

    while ((temp != NULL)||(count != index)){
        temp = temp->next;
        count++;
    }

    if (temp == NULL){
        printf("INDEX OUT OF RANGE");
    } else {
        node->next = temp->next;
        temp->next = node;
    }
}

void display(LLIST* pl){
    NODE* temp = pl->head;

    if(temp== NULL){
        printf("EMPTY LIST");
        return;
    } else{
        while (temp != NULL){
            printf("-->%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void deleteAlternate(LLIST *head)
{
    if (head->head == NULL)
        return;
  
    /* Initialize prev and node to be deleted */
    NODE *prev = head->head;
    NODE *node = head->head->next;
  
    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->next = node->next;
  
        /* Free memory */
        free(node);
  
        /* Update prev and node */
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }

    printf("DELETED ALL ALTERNATIVE ELEMENTS. CURRENT LIST:\n");
    display(head);
}