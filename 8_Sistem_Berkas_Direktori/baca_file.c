#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fh;
    int ch;
    fh = fopen("Praktikum_IX.txt", "r");
    if (fh == NULL)
    {
        puts("Can't open that file!");
        exit(1);
    }
    while ((ch = fgetc(fh)) != EOF)
        putchar(ch);
    fclose(fh);
    return (0);
}