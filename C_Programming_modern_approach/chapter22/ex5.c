#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *orig_fp, *new_fp;
    int orig_char, new_char;

    if (argc < 3)
    {
        fprintf(stderr, "usage: ex5 input_file outout_file\n");
        exit(EXIT_FAILURE);
    }

    if ((orig_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "file open error: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((new_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "file open error: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((orig_char = fgetc(orig_fp)) != EOF)
    {
        new_char = orig_char ^ KEY;
        fputc(new_char, new_fp);
    }

    fclose(orig_fp);
    fclose(new_fp);
    return 0;
}