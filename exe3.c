#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define N 3
#define ROWS 4
#define COLS 5

typedef struct node{
    Triad data;
    struct node* next;
} node;

typedef struct triad
{
    int i, j, value;
} Triad;

Triad createThree(int i, int j, int value);
node* createNode(Triad data,node* next);
void createThreeLists(int **A, int rows, int cols, node **pL1, node **pL2);
void insert_to_list(node **head ,Triad data);
void print_list(node* head);
void free_list(node** head);

int main()
{
    int A[ROWS][COLS] ={
        3, 2, 5, 3, 6,
        8, 3, 3, 6, 7,
        0, 6, 4, 5, 6,
        9, 8, 1, 6, 1,
    };
    
    Triad t = createThree()
    createNode()

}

Triad createThree(int i, int j, int value)
{
    Triad t;
    t.i=i;
    t.j=j;
    t.value=value;
    return t;
}

node *createNode(Triad data, node *next)
{
    Triad c = data;
    node* item = (node*)malloc(sizeof(node));
    item->data = c;
    item->next = next;
    return item;
}

void print_list(node* head)
{
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n"); 
}

void free_list(node** head){
    node* temp = *head;
    while(*head != NULL){
        *head = (*head)->next;
        free(temp);
        temp = *head;
    }
}

void createThreeLists(int **A, int rows, int cols, node **pL1, node **pL2)
{

}

void insert_to_list(node **head ,Triad data)
{
    node* ptr = *head;
    node* item = createNode(data, (*head));
    if(*head == NULL){
        *head = item;
        return;
    }
        
    if(){
        item->next = *head;
        *head = item;
        return;
    }
    
    while(ptr->next != NULL && ptr->next->c < c){
        ptr = ptr->next;
    }

    item->next = ptr->next;
    ptr->next = item;
}
