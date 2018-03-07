#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ex2.exe filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "file open error\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (islower(ch))
            printf("%c", toupper(ch));
        else
            printf("%c", ch);
    }
    
    fclose(fp);
    return 0;
}