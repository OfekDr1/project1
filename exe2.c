#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define N 3
#define ROWS 4
#define COLS 4

//int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
int neighborMax(int A[ROWS][COLS], int rows, int cols, int i, int j);
//int** allocMatrix(int rows, int cols);
int max(int a, int b);
int** allocMatrix(int rows, int cols);
int** matrixMaxNeighbor(int A[ROWS][COLS], int rows, int cols);
void print_Mat(int** mat, int rows, int cols);

int main() {
	int A[ROWS][COLS] = { 5, 12, 6 , 8 , 4 ,7, 1 ,9 , 13, 20 , 5, 2 , 18, 10, 2, 6 };
	//print_Mat(A[ROWS][COLS], ROWS, COLS);
	int** B = matrixMaxNeighbor(A, ROWS, COLS);
	print_Mat(B, ROWS, COLS);
}

int neighborMax(int A[ROWS][COLS], int rows, int cols, int i, int j)//לבדוק האם מקבלים מטריצה ריקה
{
	int maxVal = -214748648; // מינימום של int

	if (i > 0)
		maxVal = max(maxVal, A[i - 1][j]);
	if (i < rows - 1)
		maxVal = max(maxVal, A[i + 1][j]);
	if (j > 0)
		maxVal = max(maxVal, A[i][j - 1]);
	if (j < cols - 1)
		maxVal = max(maxVal, A[i][j + 1]);

	return maxVal;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int** allocMatrix(int rows, int cols)
{
	int** mat = (int**)calloc(rows,sizeof(int*)); // הקצאה דינמית של שורות
	for (int i = 0; i < rows; i++)
		mat[i] = (int*)calloc(cols, sizeof(int)); // הקצאה דינמית של שורות

	return mat;
}

int** matrixMaxNeighbor(int A[ROWS][COLS], int rows, int cols) {
	int** B = NULL;
	B = allocMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			B[i][j] = neighborMax(A, rows, cols, i, j);
		}
	}

	return B;
}

void print_Mat(int** mat, int rows, int cols)
{
	int i, j;
	//a = NULL;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%8d", mat[i][j]);
		printf("\n");
	}
}
