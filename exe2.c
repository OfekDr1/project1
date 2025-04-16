#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define N 3
#define ROWS 4
#define COLS 5

int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
int neighborMax(int A[][N], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);
int max(int a, int b);

int main(){
    int A[N][N]={1,2,3,4,5,6,7,8,9};
    printf("%d",neighborMax(A,N,N,0,0));
}

int neighborMax(int A[][N], int rows, int cols, int i, int j)//לבדוק האם מקבלים מטריצה ריקה
{
if(i==0)//מקרה קיצון שורה ראשונה
{
    if (j==0)
        return max(A[i+1][j],A[i][j+1]);
    else if (j==cols-1)
        return max(A[i-1][j],A[i][j+1]);
    else 
        return max(max(A[i][j-1],A[i][j+1]),A[i+1][j]);
} 
if(j==0)//מקרה קיצון טור ראשון
{
    if (i==rows-1)
         return max(A[i+1][j],A[i][j+1]);
    else
         return max(max(A[i-1][j],A[i+1][j]),A[i][j+1]);
}
if(i==rows-1)//מקרה קיצון שורה אחרונה
{
    if (j==cols-1)
     return max(A[i-1][j],A[i][j-1]);
    else
      return max(max(A[i][j-1],A[i-1][j]),A[i][j+1]); 
}
if(j=cols-1)//מקרה קצון טור אחרון
{
return max(max(A[i-1][j],A[i][j-1]),A[i+1][j]);
}
return max(max(A[i+1][j],A[i-1][j]),max(A[i][j-1],A[i][j-1]));
}

int max(int a, int b) {
    return a > b ? a : b;
}