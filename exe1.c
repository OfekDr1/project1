#include <stdio.h>
#include <malloc.h>
#define N 3

typedef struct number
{
    unsigned long long num;
    int sum;
} number;

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int* read_data(int* p_counter);
int digitSum(unsigned long long num);
int isPrime(int num);
void printArray(number* arr, int size);
void Ex1();

int main() {
    Ex1();
}

void Ex1()
{
    unsigned long long n1 = 10, n2 = 30;
    int size = 0;

    number* result = primeSums(n1, n2, &size);

    printf("Found %d numbers where digit sum is prime:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Number: %llu, Digit Sum: %d\n", result[i].num, result[i].sum);
    }

    free(result);
<<<<<<< HEAD

=======
	
>>>>>>> cb4d5c03bc17cdfab9f67e10421d3d2045cb8404
}

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
    int temp = 0;
    int k = 0;
    int size = 2;
    number* arr = (number*)malloc(sizeof(number));
<<<<<<< HEAD
    for (int i = n1; i <= n2; i++) {
=======
   
    for(int i = n1; i <= n2; i++){
>>>>>>> f11b3713f69fbd604f3b77c614947643755f6faa
        temp = digitSum(i);
        if (isPrime(temp)) 
        {
            if (size = k)
            {
                arr = (number*)realloc(arr,size * sizeof(number));
                size *= 2;
            }
            arr[k].num = i;
            arr[k++].sum = temp;
 
        }
    }
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
<<<<<<< HEAD
<<<<<<< HEAD
    for (i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return 0;
=======
    for (i = 2; num <= i*i; i++) {
=======
    for (i = 2; i * i <= num; i++) {
>>>>>>> f11b3713f69fbd604f3b77c614947643755f6faa
        if (num % i == 0) 
		return 0;
>>>>>>> cb4d5c03bc17cdfab9f67e10421d3d2045cb8404
    }
    return 1;
}

<<<<<<< HEAD
<<<<<<< HEAD
//int* read_data(int* p_counter) {
//    int i = 0, num, * a, * temp, size = 2; //start with reading 2 integers
//    a = temp = (int*)realloc(NULL, size * sizeof(int)); //malloc(size * sizeof(int))
//    if (!temp) return NULL;
//    printf("Enter the numbers:\n");
//    while (temp && scanf("%d", &num) == 1) { //successful allocation and correct input
//        a = temp;
//        a[i++] = num;
//        if (i == size) { //memory fully consumed
//            size *= 2;
//            temp = (int*)realloc(a, size * sizeof(int));
//        } //if
//    } //while
//    *p_counter = i;
//    a = (int*)realloc(a, *p_counter * sizeof(int));
//    return a;
//}
=======
// int* read_data(int* p_counter) {
// 	int i = 0, num, * a, * temp, size = 2; //start with reading 2 integers
// 	a = temp = (int*)realloc(NULL, size * sizeof(int)); //malloc(size * sizeof(int))
// 	if (!temp) return NULL;
// 	printf("Enter the numbers:\n");
// 	while (temp && scanf("%d", &num) == 1) { //successful allocation and correct input
// 		a = temp;
// 		a[i++] = num;
// 		if (i == size) { //memory fully consumed
// 			size *= 2;
// 			temp = (int*)realloc(a, size * sizeof(int));
// 		} //if
// 	} //while
// 	*p_counter = i;
// 	a = (int*)realloc(a, *p_counter * sizeof(int));
// 	return a;
// 	}
>>>>>>> cb4d5c03bc17cdfab9f67e10421d3d2045cb8404
=======
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
>>>>>>> f11b3713f69fbd604f3b77c614947643755f6faa
