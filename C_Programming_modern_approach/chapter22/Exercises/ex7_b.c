#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool is_compressed_file(char *arg);
char *make_output_filename(char *arg);

int main(int argc, char *argv[])
{
    FILE *fpin, *fpout;
    char *fnout;
    char cnt, content;

    if (argc != 2)
    {
        fprintf(stderr, "[x] usage: ex7_b filename\n");
        exit(EXIT_FAILURE);
    }

    if (!is_compressed_file(argv[1]))
    {
        fprintf(stderr, "[x] invalid extension\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "[x] error occured in fopen()\n");
        exit(EXIT_FAILURE);
    }
    fnout = make_output_filename(argv[1]);
    if ((fpout = fopen(fnout, "wb")) == NULL)
    {
        fprintf(stderr, "[x] error occured in fopen()\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        cnt = fgetc(fpin); // 첫번째 바이트
        if (feof(fpin))
            break;
        content = fgetc(fpin); // 두번째 바이트       
        for (int i = 0; i < cnt; i++)
        {
            fputc(content, fpout);
        }
    }

    fclose(fpin);
    fclose(fpout);
    return 0;
}

char *make_output_filename(char *arg)
{
    const char *ext = ".uncompressed_file";
    char *fnout;

    fnout = (char *) malloc(sizeof(char) * (strlen(arg) + strlen(ext) + 1));
    memset(fnout, 0, strlen(fnout));
    strncpy(fnout, arg, strlen(arg)+1);
    char *ptr = fnout;
    ptr = ptr + strlen(ptr) - 1;
    while (*ptr != '.')
        ptr--;
    *ptr = '\0';
    strncat(ptr, ext, strlen(fnout) + strlen(ext));

    return fnout;
}

bool is_compressed_file(char *arg)
{
    const char *ext = ".rle";
    bool is_cf = true;

    while (*arg++);
    while (*ext++);
    *arg--; *ext--;
    *arg--; *ext--;
    
    while (*arg && *ext)
    {
        if (*arg != *ext)
        {
            is_cf = false;
            break;
        }
        arg--; ext--;
    }

    return is_cf;
}
