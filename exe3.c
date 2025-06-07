#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <malloc.h>

void decode(char* text);

int main() {
    char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    decode(str);
    puts(str);
}


void decode(char* text)
{
    int i = 0;
    int counter;
    while (text[i] != '\0') {
        counter = -1;
        while (text[i] != ' '&&text[i]!='\0')
        {
            text[i] += counter;
            counter--;
            i++;
        }
        if (text[i] == ' ')
            i++;
    }
}