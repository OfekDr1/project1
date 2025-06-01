#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define PATH "C:\\Users\\oriam\\Documents\\GitHub\\project1\\input.txt"

void createFile(char* filename);
char commonLetter(char* filename);

int main(){
    char result;
    //createFile(PATH);
    
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
    int maxCount = 0;
    char c, maxChar; 
    int monim[26] = {0};

    if(fp == NULL){
        fclose(fp);
        return '\0';
    }
    
    while((c = fgetc(fp)) != EOF){
        if(c >= 'a' && c <= 'z')
            monim[c - 'a']++;
        else if(c >= 'A' && c <= 'Z')
            monim[c - 'A']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(monim[i] >= maxCount){
            maxCount = monim[i];
            maxChar = 'A' + i; 
        }
    }

    fclose(fp);

    return maxChar;
}