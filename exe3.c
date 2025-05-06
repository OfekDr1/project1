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

Triad createThree(int i, int j, int value);


int main()
{

}

Triad createThree(int i, int j, int value)
{
    Triad t;
    t.i=i;
    t.j=j;
    t.value=value;
    return t;
}