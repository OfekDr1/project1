#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define PATH "C:\\Users\\oriam\\Documents\\GitHub\\project1\\input.txt"

void createFile(char* filename);
char commonLetter(char* filename);

int main(){
    char result;
    createFile(PATH);
    
    result = commonLetter(PATH);
    printf("Result is = %c", result);
}

void createFile(char* filename)
{
    FILE* fp = fopen(filename, "w");
    char c;
    if(fp == NULL) fclose(fp);
    
    printf("Enter text (To stop - Enter Ctrl-z): ");
    while((c = getchar()) != EOF){
        fputc(c, fp);
    }
   
    fclose(fp);
}

char commonLetter(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) fclose(fp);
    int monim[26] = {0};
    char c;
    while((c = fgetc(fp)) != EOF){
        if(c <= 'a' && c >= 'z')
            monim[c - 'a']++;
        else if(c <= 'A' && c >= 'Z')
            monim[c - 'A']++;
    }
    int maxCount = 0;
    char maxChar; 
    for(int i = 0; i < 26; i++){
        if(monim[i] >= maxCount){
            maxCount = monim[i];
            maxChar = 'a' + i; 
        }
    }

    fclose(fp);

    return maxChar;
}