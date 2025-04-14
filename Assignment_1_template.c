/*
    Assigned by:
    Student1_Full_Name #ID
    Student2_Full_Name #ID
*/

#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <stdio.h>
#include <malloc.h>

/* Constant definitions */

#define N 3
#define ROWS 4
#define COLS 5

/* Type definitions */

typedef struct number
{
    unsigned long long num;
    int sum;
} number;

typedef struct triad
{
    int i, j, value;
} Triad;

typedef struct item
{
    Triad data;
    struct item* next;
} Item;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);

/* Declarations of auxiliary functions */

int isPrime(int num);
int digitSum(unsigned long long num);

int neighborMax(int A[][COLS], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);

Triad createThree(int i, int j, int value);
// insert - to declare the function yourself

void printArray(number* arr, int size);
void inputMatrix(int A[][COLS], int rows, int cols);
void printMatrix(int A[][COLS], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void freeMatrix(void** A, int rows);
void inputDynamicMatrix(int** A, int rows, int cols);
void printList(Item* lst);
void freeList(Item* lst);

/* ------------------------------- */

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do
        {
            for (i = 1; i <= N; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select)
            {
            case 1: Ex1(); break;
            case 2: Ex2(); break;
            case 3: Ex3(); break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}


/* Function definitions */

void Ex1()
{
  
    unsigned long long n1 , n2 ;
    printf("Enter two numbers\n");
    printf("1st - ");
    scanf("%lld", &n1);
    printf("2nd - ");
    scanf("%lld", &n2);
    int size = 0;

    number* result = primeSums(n1, n2, &size);

    printf("Found %d numbers where digit sum is prime:\n", size);
    printArray(result, size);
    free(result);
}

void Ex2()
{
    /* Called functions:
        inputMatrix, printMatrix, matrixMaxNeighbor, printDynamicMatrix, freeMatrix */
        /* Write Code Here! */
}

void Ex3()
{
    /* Called functions:
        allocMatrix, inputDynamicMatrix, printDynamicMatrix, createThreeLists, printList, freeMatrix, freeList */
        /* Write Code Here! */
}

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
    int temp = 0;
    int k = 0;
    int size = 2;
    number* arr = (number*)malloc(sizeof(number));
    for (int i = n1; i <= n2; i++) 
    {
        temp = digitSum(i);
        if (isPrime(temp))
        {
            if (size = k)
            {
                size *= 2;
                arr = (number*)realloc(arr, size * sizeof(number));
                
            }
            arr[k].num = i;
            arr[k++].sum = temp;
        }
    }
    *p_size = k;
    arr = (number*)realloc(arr, (*p_size) * sizeof(number));
    return arr;
}

void printArray(number* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Number: %llu, Digit Sum: %d\n", arr[i].num, arr[i].sum);
    }
}

int digitSum(unsigned long long num)
{
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int isPrime(int num) {
    if (num < 2) return 0;
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}


int** matrixMaxNeighbor(int A[][COLS], int rows, int cols)
{
    /* Called functions:
        neighborMax, allocMatrix */
        /* Write Code Here! */
}
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2)
{
    /* Called functions:
        createThree, insert */
        /* Write Code Here! */
}

/* Definitions of auxiliary functions */

/* Write Definitions Here! */

/* -------------------- */