#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fh;
    fh = fopen("Praktikum_IX.txt", "w");
    if (fh == NULL)
    {
        puts("Can't open that file!");
        exit(1);
    }
    fprintf(fh, "Look what I made!\n");
    fclose(fh);
    return (0);
}