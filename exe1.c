#include <stdio.h>
#include <malloc.h>
#define N 3

typedef struct number
{
    unsigned long long num;
    int sum;
} number;

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int digitSum(unsigned long long num);
int isPrime(int num);
void printArray(number* arr, int size);

int main() {
    unsigned long long n1 = 10, n2 = 30;
    int size = 0;

    number* result = primeSums(n1, n2, &size);

    printf("Found %d numbers where digit sum is prime:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Number: %llu, Digit Sum: %d\n", result[i].num, result[i].sum);
    }
    printArray(result, size);
    free(result);
}

number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
    int temp = 0;
    int k = 0;
    int size = 2;
    number* arr = (number*)malloc(sizeof(number));
    for (int i = n1; i <= n2; i++) {
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
    for (i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
