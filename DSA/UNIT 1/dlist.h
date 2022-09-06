#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node;

typedef struct list{
    node* head;
} list;

void initList(list*);
void display(list*);
node* createNode(int);
void insertFront(list*, int);
void deleteFront(list*);
void insertLast(list*, int);
void deleteLast(list*);
void insertPos(list*, int, int);
void insertLast(list*, int);

void initList(list* pl){
    pl->head = NULL;
}

void display(list* pl){
    if (pl->head == NULL){
        printf("LIST EMPTY\n");
    } else{
        node* temp = pl->head;
        for(int i = 0; 1; i++){
            if (temp == NULL){
                break;
            } else {
                printf("-> %d\n", temp->data);
                temp = temp->next;
            }
        }
    }
    printf("DISPLAY DONE\n");
}

node* createNode(int data){
    node* Node = (node*) malloc(sizeof(node));
    Node->data = data;
    Node->next = NULL;
    Node->previous=NULL;
    return Node;
}

void insertFront(list* pl, int data){
    node* Node = createNode(data);
    if(pl->head == NULL){
        pl->head = Node;
    } else {
        Node->next = pl->head;
        pl->head->previous = Node;
        pl->head = Node;
    }
    return;
}

void insertLast(list* pl, int data){
    node* Node = createNode(data);
    if(pl->head == NULL){
        pl->head = Node;
        return;
    }
    node* temp = pl->head;
    while(1){
        if(temp->next == NULL){
            temp->next = Node;
            Node->previous = temp;
            break;
        }
        temp = temp->next;
    }
    return;
}

void deleteFront(list* pl){
    if (pl->head == NULL){
        printf("NO ELEMENTS");
    } else {
        node* temp = pl->head;
        pl->head = pl->head->next;
        free(temp);
    }
}

void deleteLast(list* pl){
    node* temp = pl->head;
    if (pl->head == NULL){
        printf("LIST IS EMPTY");
    } else {
        while(1){
            if (temp->next == NULL){
                temp->previous->next = NULL;
                free(temp);
                break;
            }
            temp = temp->next;
        }
    }
}

void insertLast(list* pl, int data){
    node* Node = createNode(data);
    node* temp = pl->head;

    if (pl->head == NULL){
        pl->head = Node;
    } else {
        while(1){
            if (temp->next == NULL){
                temp->next = Node;
                Node->previous = temp;
                break;
            }
            temp = temp->next;
        }
    }
}

void insertPos(list* pl, int index, int data){
    node* Node = createNode(data);
    node* temp = pl->head;
    int count = 0;

    if (pl->head == NULL){
        printf("LIST IS EMPTY");
    } else {
        while(1){
            count++;
            if (count == index){
                Node->next = temp->next;
                Node->previous = temp;
                Node->next->previous = Node;
                Node->previous->next = Node;
                break;
            }
            temp = temp->next;
        }
    }
}

void deletePos(list* pl, int index){
    node* temp = pl->head;
    int count = 0;

    if (pl->head == NULL){
        printf("LIST IS EMPTY");
    } else {
        while(1){
            if (count == index){
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                free(temp);
                break;
            } else if(temp->next == NULL){
                printf("INDEX NOT IN LIST\n");
                break;
            }
            count++;
            temp = temp->next;
        }
    }
}