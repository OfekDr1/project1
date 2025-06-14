#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define N 3

char** split(char letter, char* str, int* p_size);
void printStringsArray(char** str_arr, int size);
void freeMatrix(void** A, int rows);

int main() {
    char str[100] = "google is Good";
    int psize = 0;
    char** newstr = split('g', str, &psize);
    printStringsArray(newstr,psize);
}

char** split(char letter, char* str, int* p_size) {
    int i = 0, count = 0, countLetters = 0;
    while (str[i] != '\0') {
        if ((tolower(str[i]) == tolower(letter)) && (i == 0 || str[i - 1] == ' ')) {
            count++;
        }
        i++;
    }

    *p_size = count;
    if (count == 0) return NULL;

    char** array_of_strings = malloc(count * sizeof(char*));
    i = 0;
    int h = 0;

    while(str[i] != '\0') {
        if ((tolower(str[i]) == tolower(letter)) && (i == 0 || str[i - 1] == ' ')) 
        {
            int j = i, countLetters = 0;
            while (str[j] != ' ' && str[j] != '\0') {
                countLetters++;
                j++;
            }
            array_of_strings[h] = malloc((countLetters + 1) * sizeof(char));
            h++;
    }
        i++;
    }
    i = 0;
    h = 0;
    while (str[i] != '\0') {
        if ((tolower(str[i]) == tolower(letter)) && (i == 0 || str[i - 1] == ' ')) {
            int j = i, k = 0;
            while (str[j] != ' ' && str[j] != '\0') {
                array_of_strings[h][k++] = str[j++];
            }
            array_of_strings[h][k] = '\0';
            h++;
        }
        i++;
    }

    return array_of_strings;
}

void printStringsArray(char** str_arr, int size) {
    for (int i = 0; i < size; i++) {
        if (str_arr[i] != NULL) {
            printf("%s\n", str_arr[i]);
        }
        else {
            printf("(null)\n");
        }
    }
}
 
