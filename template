/*
    Assigned by:
    Ofek drori #211785027
    Ori Amsalem #206508731
*/
#define _CRT_SECURE_NO_WARNINGS

/* Libraries */
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  
#include <ctype.h>   

/* Constant definitions */
#define N 3

/* Function declarations */
void Ex1();
void Ex2();
void Ex3();

char** split(char letter, char* str, int* p_size);
void printStringsArray(char** str_arr, int size);
void createFile(char* filename);
char commonLetter(char* filename);
void decode(char* text);

/* Declarations of auxiliary functions */
void freeMatrix(void** A, int rows);

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
    char str[100] = "Rony Goodman got a good mark";
    int psize = 0;
    char** newstr = split('g', str, &psize);
    if (newstr != NULL) {
        printStringsArray(newstr, psize);

        freeMatrix((void**)newstr, psize);
    }
}

void Ex2()
{
    char result;
    createFile("input.txt");
    result = commonLetter("input.txt");
    if (result != '\0')
        printf("Result is = %c", result);
    else
        printf("Error opening file for reading\n");
}

void Ex3()
{
    char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    decode(str);
    puts(str);
}

char** split(char letter, char* str, int* p_size)
{
    int i = 0, count = 0;

    while (str[i] != '\0') {
        if ((tolower(str[i]) == tolower(letter)) && (i == 0 || str[i - 1] == ' ')) {
            count++;
        }
        i++;
    }

    *p_size = count;
    if (count == 0) return NULL;

    char** array_of_strings = (char**)malloc(count * sizeof(char*));
    if (array_of_strings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        *p_size = 0;
        return NULL;
    }

    i = 0;
    int h = 0;

    while (str[i] != '\0') {
        if ((tolower(str[i]) == tolower(letter)) && (i == 0 || str[i - 1] == ' ')) {
            int j = i, countLetters = 0;
            while (str[j] != ' ' && str[j] != '\0') {
                countLetters++;
                j++;
            }
            array_of_strings[h] = (char*)malloc((countLetters + 1) * sizeof(char));
            if (array_of_strings[h] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                freeMatrix((void**)array_of_strings, h);
                *p_size = 0;
                return NULL;
            }
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

void createFile(char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    int c;
    printf("Enter text (To stop - Enter Ctrl-Z then Enter):\n");
    while ((c = getchar()) != EOF) {
        fputc(c, fp);
    }

    fclose(fp);
}

char commonLetter(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return '\0';
    }

    int maxCount = 0;
    char maxChar = '\0';
    int monim[26] = { 0 };
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (c >= 'a' && c <= 'z')
            monim[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
            monim[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (monim[i] >= maxCount) {
            maxCount = monim[i];
            maxChar = 'A' + i;
        }
    }

    fclose(fp);
    return maxChar;
}

void decode(char* text)
{
    int i = 0;
    int counter;
    while (text[i] != '\0') {
        counter = -1;
        while (text[i] != ' ' && text[i] != '\0')
        {
            text[i] += counter;
            counter--;
            i++;
        }
        if (text[i] == ' ')
            i++;
    }
}

void freeMatrix(void** A, int rows)
{
    if (A == NULL)
        return;

    for (int i = 0; i < rows; i++) {
        if (A[i] != NULL) {
            free(A[i]);
        }
    }
    free(A);
}

/* ------------------- */
