#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define OFFSET 10

int main(int argc, char *argv[])
{
    FILE *fp;
    bool is_eof = false;
    char ch;
    int i;

    if (argc != 2)
    {
        printf("Usage: ex6 filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");
    for (int ost = 0; !is_eof; ost += OFFSET)
    {
        printf("%6d  ", ost);
        for (i = 0; i < OFFSET; i++)
        {
            ch = (char)fgetc(fp);
            if (ch == EOF)
                break;
            printf("%02X ", ch);
        }
        for ( ; i < OFFSET; i++)
            printf("   ");
        printf(" ");
        fseek(fp, ost, SEEK_SET);
        for (int j = 0; j < OFFSET; j++)
        {
            ch = (char)fgetc(fp);
            if (ch == EOF) 
            {
                is_eof = true;
                break;
            }
            if (isprint(ch))
                printf("%c", ch);
            else 
                printf(".");
        }
        printf("\n");
        
    }

    fclose(fp);
    return 0;
}