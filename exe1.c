#include <stdio.h>
#include <malloc.h>
#define N 3

typedef struct number
{
	unsigned long long num;
	int sum;
} Number;

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int* read_data(int* p_counter);
int digitSum(unsigned long long num);


int main(){
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

int* read_data(int* p_counter) {
	int i = 0, num, * a, * temp, size = 2; //start with reading 2 integers
	a = temp = (int*)realloc(NULL, size * sizeof(int)); //malloc(size * sizeof(int))
	if (!temp) return NULL;
	printf("Enter the numbers:\n");
	while (temp && scanf("%d", &num) == 1) { //successful allocation and correct input
		a = temp;
		a[i++] = num;
		if (i == size) { //memory fully consumed
			size *= 2;
			temp = (int*)realloc(a, size * sizeof(int));
		} //if
	} //while
	*p_counter = i;
	a = (int*)realloc(a, *p_counter * sizeof(int));
	return a;
	}

    void Ex1()
{
	/* Called functions: 
		primeSums, printArray */
	/* Write Code Here! */
}

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size){
    
}

int digitSum(unsigned long long num)
{
    int sum = 0;
    while()
}
