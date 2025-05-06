#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define N 3
#define ROWS 4
#define COLS 5

typedef struct node{
    char data;
    struct node* next;
} node;

typedef struct triad
{
    int i, j, value;
} Triad;

Triad createThree(int i, int j, int value);
node* createNode(int data,node* next);
void createThreeLists(int **A, int rows, int cols, node **pL1, node **pL2);
void print_list(node* head);
void free_list(node** head);

int main()
{
    int arr[ROWS][COLS] ={
        3, 2, 5, 3, 6,
        8, 3, 3, 6, 7,
        0, 6, 4, 5, 6,
        9, 8, 1, 6, 1,
    };
    

}

Triad createThree(int i, int j, int value)
{
    Triad t;
    t.i=i;
    t.j=j;
    t.value=value;
    return t;
}

node *createNode(int data, node *next)
{
    int c = data;
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
