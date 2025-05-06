#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define N 3
#define ROWS 4
#define COLS 5

typedef struct triad
{
    int i, j, value;
} Triad;

typedef struct node{
    Triad data;
    struct node* next;
} node;

Triad createThree(int i, int j, int value);
node* createNode(Triad data,node* next);
void createThreeLists(int **A, int rows, int cols, node **pL1, node **pL2);
void insert_to_list(node **head ,Triad data);
void printDynamicMatrix(int** A, int rows, int cols);
void inputDynamicMatrix(int** A, int rows, int cols);
int** allocMatrix(int rows, int cols);
void freeMatrix(void** A, int rows);
void print_list(node* head);
void free_list(node* head);

int main()
{
    node *pL1 = NULL, *pL2 = NULL;
	int rows, cols;

	printf("please enter amount of rows for the matrix: \n");
	scanf("%d", &rows);
	printf("please enter number of cols for the matrix: \n");
	scanf("%d", &cols);

	int **c = allocMatrix(rows, cols);
	inputDynamicMatrix(c, rows, cols);
	createThreeLists(c, rows, cols, &pL1, &pL2);

	printf("L1:\n");
	print_list(pL1);
	printf("L2:\n");
	print_list(pL2);

	freeMatrix((void**)c, rows);
	free_list(pL1);
	free_list(pL2);
}

void printDynamicMatrix(int** A, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++)
	{
		printf("\n");
		for (j = 0; j < cols; j++)
		{
			printf("%d ", A[i][j]);
		}
	}
}

void inputDynamicMatrix(int** A, int rows, int cols) {

	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("Enter value for the matrix at row: %d and col %d: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
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
    if (item == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	}
    item->data = c;
    item->next = next;
    return item;
}

void createThreeLists(int **A, int rows, int cols, node **pL1, node **pL2)
{
	int i, j;
	Triad triad_Insert;
	// Condition: if i + j == A[i][j]
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (i + j == A[i][j])
{
				triad_Insert = createThree(i, j, i + j);
				insert_to_list(pL1, triad_Insert);
			}
			if (A[i][j] - j == j - i)
			{
				triad_Insert = createThree(i, j, A[i][j]);
				insert_to_list(pL2, triad_Insert);
			}
		}
	}
}

void insert_to_list(node **head ,Triad data)
{
    node* item = createNode(data, NULL);
    if (*head == NULL) {
        *head = item;
    } else {
        node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = item;
    }
}


void print_list(node* head)
{
    while(head != NULL){
        printf("->i: %d, j: %d, value: %d\n", head->data.i, head->data.j, head->data.value);
        head = head->next;
    }
}

void free_list(node* head){
    node* temp = head;
    while(head != NULL){
        temp = head;
        head = (head)->next;
        free(temp);
    }
}

int** allocMatrix(int rows, int cols) {
	int i,j;

	//alloc memory for the rows pointers:
	int** matrixAlloc = (int**) calloc(rows,sizeof(int*)) ;
	if (matrixAlloc == NULL) {
		printf("Failed to allocate the matrix\n");
		return NULL;
	}

	//alloc memory for the cols on each row.
	for(i = 0; i < rows; i++) {
		matrixAlloc[i] = (int*) calloc (sizeof(int),cols);
		if (matrixAlloc[i] == NULL) {
			printf("Failed to allocate memory for columns\n");
			// Free already allocated memory before exiting
			freeMatrix((void**)matrixAlloc, i);
			return NULL;
		}
	}

	return matrixAlloc;
}

void freeMatrix(void** A, int rows) {
	int i;

	for (i = 0; i < rows; i++) {
		free(A[i]);
	}
	free(A);
}
