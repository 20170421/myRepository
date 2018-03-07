#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc < 2)
    {
        fprintf(stderr, "usage: ex3 filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "file open error: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        printf("\n");
        fclose(fp);
    }
    return 0;
}